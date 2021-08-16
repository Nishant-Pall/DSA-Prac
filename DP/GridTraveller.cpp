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
typedef vector<vector<pdd> > vvdd;
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

vvi F(100, vi(100, -1));

int solve(int m, int n) {
    // RECURSIVE SOLUTION
    // TIME : O(2^(n+m))
    // SPACE : O(n+m)
    // if (n == 1 && m == 1) return 1;
    // if (!n || !m) return 0;
    // return solve(m - 1, n) + solve(m, n - 1);

    // MEMOIZATION SOLUTION
    // TIME : O(m*n)
    // SPACE : O(m+n)
    // if (!n || !m) return 0;

    // if (m == 1 && n == 1) {
    //     F[m][n] = 1;
    //     return 1;
    // } else {
    //     if (F[m - 1][n] == -1) F[m - 1][n] = solve(m - 1, n);
    //     if (F[m][n - 1] == -1) F[m][n - 1] = solve(m, n - 1);
    //     return F[m - 1][n] + F[m][n - 1];
    // }

    // TABULATION
    vvi dp(m, vi(n, 0));

    // count of paths to reach any row is 1
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    // count of paths to reach any col is 1
    for (int i = 0; i < n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m = 3, n = 3;
    cout << solve(m, n);
    return 0;
}