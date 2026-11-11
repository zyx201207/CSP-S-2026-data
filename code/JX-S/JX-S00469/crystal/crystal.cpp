#include <bits/stdc++.h>
#define int long long
using namespace std;

int T = 1;
const int N = 5e5 + 10;
int n, m, mid, cnt;
int arr[N], num[N], to[N];
map<int, int> mp;

bool Cmp(int& a, int& b) {
    return labs(a - mid) < labs(b - mid);
}

int Check() {
    int k = 0, e = m, g = to[mid];
    for (int i = 1; i <= n; i++) {
        if (arr[i] > g) continue;
        if (e >= g - arr[i]) {
            e -= g - arr[i];
            k++;
        }
    }
    return k;
}

void Solve() {
    cin >> n >> m;
    //int l = 1e18, r = -1e13, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (arr[i] != arr[i - 1] || i == 1) {
            mp[arr[i]] = ++cnt;
            to[cnt] = arr[i];
        }
        num[cnt]++;
    }
    int l = 1, r = cnt, ans = 0;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        int re = Check();
        if (re >= ans) {
            ans = re;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (T--) {
        Solve();
    }
    return 0;
}
