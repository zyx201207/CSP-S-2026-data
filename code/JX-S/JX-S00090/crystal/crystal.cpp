#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 5;
ll a[N], cha[N], pre[N];

inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') {
            f = -1;
            c = getchar();
        }
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}

inline ll readll() {
    ll x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') {
            f = -1;
            c = getchar();
        }
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    ll m;
    n = read(); m = readll();
    for (int i = 1; i <= n; i++) {
        a[i] = readll();
    }
    sort(a + 1, a + n + 1);
    vector<int> b;
    b.reserve(n + 1);
    cha[1] = 0;
    for (int i = 1; i <= n; i++) {
        cha[i] = abs(a[i] - a[i - 1]);
        pre[i] = pre[i - 1] + cha[i];
        while (!b.empty() && pre[b.back()] == pre[i]) b.pop_back();
        b.push_back(i);
    }
    int ans = 0;
    for (int i = 1; i < b.size(); i++) {
        ll cnt = 0;
        int r = b[i];
        for (int l = b[i - 1]; l >= 0; l--) {
            ll c = pre[r] - pre[l];
            if (cnt + c <= m) {
                cnt += c;
                ans = max(ans, r - l + 1);
            }
            else break;
        }
    }
    cout << ans << "\n";
    return 0;
}
