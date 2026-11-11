#include <bits/stdc++.h>
using namespace std;

#define FILENAME "crystal"

#define fo(i, a, b) for (int i = a; i <= b; i++)
#define fod(i, a, b) for (int i = b; i >= a; i--)
#define rep(i, n) fo(i, 0, n - 1)
#define repd(i, n) fod(i, 0, n - 1)
#define Rep(i, n) fo(i, 1, n)
#define Repd(i, n) fod(i, 1, n)
#define all(a) a.begin(), a.end()

const long long INF_long = 9e18;

vector<long long> a;
vector<long long> sum;
long long n, m;

bool check(long long mid) {
    if (mid <= 1) return true;
    fo(i, mid - 1, n - 1) {
        long long cost = sum[i - 1] - (i - mid < 0 ? 0 : sum[i - mid]); 
        cost = a[i] * (mid - 1) - cost;
        if (cost <= m) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    a.resize(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    sum.resize(n);
    sum[0] = a[0];
    Rep(i, n - 1) {
        sum[i] = sum[i - 1] + a[i];
    }
    int l = 2, r = n;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << r;
}

int main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
}