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
typedef vector<string> vs;
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

vector<int> factorial(int N) {
    long long num = (long long)N;
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (long long i = 2; i <= num; i++) {
        dp[i] = dp[i - 1] * i;
    }
    vector<int> ans;
    cout << dp[num];
    num = dp[num];
    while (num) {
        int rem = num % 10;
        // dbg(rem);
        ans.emplace_back(rem);
        num /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> ans = factorial(30);
    // for (auto i : ans) cout << i << " ";
    return 0;
}
