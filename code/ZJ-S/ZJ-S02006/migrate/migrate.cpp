#include <bits/stdc++.h>
using namespace std;

long long x[2000005], vl[2000005], vr[2000005], cnt[2000005];
int l[2000005], r[2000005], fa[2000005];

int find_root(int x) {
    return fa[x] ? (fa[x] = find_root(fa[x])) : x;
}

void merge(int x, int y) {
    x = find_root(x); y = find_root(y);
    if (x != y) fa[x] = y;
}

int main() {
    freopen("migrate3.in", "r", stdin);
    // freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int id, T;
    cin >> id >> T;
    while (T --) {
        int n;
        long long d;
        cin >> n >> d;
        cerr << n << ' ' << d << '\n';
        for (int i = 1; i <= n; i ++) {
            cin >> x[i];
            fa[i] = 0;
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; i ++) {
            l[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
            r[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
            if (r[l[i]] == i) {
                merge(l[i], i);
            }
        }
        for (int i = 1; i <= n; i ++) {
            find_root(i);
        }
        for (int i = 1; i <= n; i ++) {
            if (!fa[i]) fa[i] = i;
        }
        for (int i = 1; i <= n; i ++) {
            ++ vl[r[i]];
            ++ vr[l[i]];
        }
        for (int i = 1; i <= n; i ++) {
            cnt[fa[i]] += vl[i];
            vl[i] = cnt[fa[i]];
        }
        for (int i = 1; i <= n; i ++) cnt[i] = 0;
        for (int i = n; i; i --) {
            cnt[fa[i]] += vr[i];
            vr[i] = cnt[fa[i]];
        }
        for (int i = 1; i <= n; i ++) ++ vl[i], ++ vr[i];
        for (int i = 1; i <= n; i ++) {
            vr[l[i]] += vr[i];
            vr[i] = 0;
        }
        for (int i = n; i >= 1; i --) {
            vl[r[i]] += vl[i];
            vl[i] = 0;
        }
        long long res = 0;
        for (int i = 1; i < n; i ++) {
            res += vr[i] * vl[i + 1];
        }
        cout << res << '\n';
    }
    return 0;
}