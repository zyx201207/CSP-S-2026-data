#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define sc if(DEBUG) cerr
const bool DEBUG = false;

const int N = 5e5 + 5;

int n;
ll m, a[N], s[N];

int get_pre(int x) {
    int l = 1, r = x, res = x;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(a[x] * (x - mid + 1) - (s[x] - s[mid - 1]) <= m) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    return res;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];

    int res = 0;
    for(int i = 1; i <= n; ++i) {
        int pre = get_pre(i);
        res = max(res, i - pre + 1);
    }

    cout << res << "\n";
    return 0;
}
