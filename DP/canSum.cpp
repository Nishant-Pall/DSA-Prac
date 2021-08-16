#include <bits/stdc++.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<pdd>> vvdd;
ll MOD = 998244353;
double eps = 1e-12;
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)   // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)  // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forr0(i, n) for (int i = (int)(n)-1; i >= 0; --i)  // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)    // reverse 1 based
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())

// MEMOIZATION
// m -> target sum
// n -> length of array
// TIME: O(m*n)
// SPACE: O(m)
// vi F(100, -1);
// bool solve(int target_sum, vi& array) {
//     if (F[target_sum] != -1) return F[target_sum];
//     if (!target_sum) return true;
//     if (target_sum < 0) return false;

//     for (auto num : array) {
//         int remainder = target_sum - num;
//         if (solve(remainder, array)) {
//             F[target_sum] = true;
//             return true;
//         }
//     }
//     F[target_sum] = false;
//     return false;
// }

// TABULATION WITH NO REPITITIONS
// bool solve(int target_sum, vi &array) {
//     int n = array.size();
//     vector<vector<bool>> dp(n + 1, vector<bool>(target_sum + 1, false));
//     for (int i = 0; i <= n; i++) dp[i][0] = true;
//     for (int i = 1; i <= target_sum; i++) dp[0][i] = false;

//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= target_sum; j++) {
//             if (j < array[i - 1]) {
//                 dp[i][j] = dp[i - 1][j];
//             } else {
//                 dp[i][j] = dp[i - 1][j] || dp[i - 1][j - array[i - 1]];
//             }
//         }
//     }
//     return dp[n][target_sum];
// }

// TABULATION WITH REPITITIONS
bool solve(int target_sum, vi &array) {
    vector<bool> dp(target_sum + 1, false);
    dp[0] = true;
    for (int i = 0; i <= target_sum; i++) {
        if (dp[i]) {
            for (auto num : array) {
                if (i + num <= target_sum) dp[i + num] = true;
            }
        }
    }
    return dp[target_sum];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vi array = {2, 3};
    cout << solve(7, array);
    return 0;
}