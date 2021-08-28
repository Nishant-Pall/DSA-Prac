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

class Solution {
   public:
    // int median(vector<vector<int>> &matrix, int r, int c) {
    //     vector<int> v;
    //     for (auto i : matrix)
    //         for (auto j : i)
    //             v.emplace_back(j);

    //     sort(v.begin(), v.end());
    //     int mid = v[v.size() / 2];
    //     return mid;
    // }
    int count(vector<vector<int>> &matrix, int k) {
        int ans = 0;
        for (auto i : matrix)
            for (auto j : i)
                if (j < k) ans++;
        return ans;
    }
    int median(vector<vector<int>> &matrix, int r, int c) {
        int n = r * c;
        int lo = 0, hi = n - 1;
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid / r][mid % r] == count(matrix, matrix[mid / r][mid % r])) {
                ans = matrix[mid / r][mid % r];
            } else if (matrix[mid / r][mid % r] > count(matrix, matrix[mid / r][mid % r])) {
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
}
