#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;

int c, t;

int n;
ll a[N], d;

struct Nod {
    int l, r;
    pii mn;
} tr[N << 2];
void pushup(int id) {
    tr[id].mn = min(tr[id << 1].mn, tr[id << 1 | 1].mn);
    if (tr[id << 1].mn.first == tr[id << 1 | 1].mn.first) {
        tr[id].mn.second = tr[id << 1].mn.second + tr[id << 1 | 1].mn.second;
    }
}
void build(int id, int l, int r) {
    tr[id].l = l; tr[id].r = r;
    if (l == r) {
        tr[id].mn = {0, 1};
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    pushup(id);
}
pii query(int id, int ql, int qr) {
    int l = tr[id].l, r = tr[id].r;
    if (ql <= l && r <= qr) {
        return tr[id].mn;
    }
    int mid = (l + r) >> 1;
    if (qr <= mid) return query(id << 1, ql, qr);
    else if (mid < ql) return query(id << 1 | 1, ql, qr);
    pii lft = query(id << 1, ql, mid), rig = query(id << 1 | 1, mid + 1, qr);
    pii ans = min(lft, rig);
    if (lft.first == rig.first) {
        ans.second = lft.second + rig.second;
    }
    return ans;
}
void modify(int id, int x, pii k) {
    int l = tr[id].l, r = tr[id].r;
    if (l == r) {
        tr[id].mn = k;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) modify(id << 1, x, k);
    else modify(id << 1 | 1, x, k);
    pushup(id);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            build(1, i, n);
            for (int j = i + 1; j <= n; j++) {
                int x = lower_bound(a + i, a + j + 1, a[j] - d) - a;
                if (x == j) break;
                pii res = query(1, x, j - 1);
                res.first++;
                // if (res.second > 2) break;
                if (res.second == 2) {
                    ans++;
                }
                modify(1, j, res);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

// 40pts. I can't get more.