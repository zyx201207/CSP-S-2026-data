#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
struct migrate {
    int now, cnt;
} mig[N][N];
int n;
long long d;
long long x[N];
/*
struct SegMentTree {
    int l, r, num;
    long long cnt;
} tree[N * 4];
void push_up (int k) {
    int lson = 2 * k, rson = 2 * k + 1;
    tree[k].num = min (tree[lson].num, tree[rson].num);
    if (tree[lson].num == tree[k].num) tree[k].cnt = tree[lson].cnt;
    if (tree[rson].num == tree[k].num) tree[k].cnt += tree[rson].cnt;
}
void build (int k, int l, int r) {
    tree[k] = {l, r, N, 0};
    if (l == r) {
        tree[k].num = 0, tree[k].cnt = 1;
        return;
    }
    int mid = (l + r) / 2;
    build (2 * k, l, mid);
    build (2 * k + 1, mid + 1, r);
    push_up (k);
}
void update (int k, int pos, int val) {
    if (tree[k].l == tree[k].r) {
        tree[k].num = min (tree[k].num, val);
        return;
    }
    int mid = (tree[k].l + tree[k].r) / 2;
    if (pos <= mid) update (2 * k, pos, val);
    else update (2 * k + 1, pos, val);
    push_up (k);
}
pair <int, int> query (int k, int L, int R) {
    if (L <= tree[k].l && tree[k].r <= R) return make_pair (tree[k].num, tree[k].cnt);
    int mid = (tree[k].l + tree[k].r) / 2;
    pair <int, int> res = make_pair (N, 0);
    if (L <= mid) {
        if (res.first > query (2 * k, L, R).first) {
            res = query (2 * k, L, R);
        }
    }
    if (R >= mid + 1) {
        if (res.first > query (2 * k, L, R).first) {
            res = query (2 * k, L, R);
        } else if (res.first == query (2 * k, L, R).first) {
            res.second += query (2 * k, L, R).second;
        }
    }
    return res;
}
*/
int main () {
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);
    int c, T; cin >> c >> T;
    while (T--) {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i], mig[i][i] = {0, 1};
        }
        long long res = 0;
        for (int u = 1; u <= n; u++) {
            for (int v = u + 1; v <= n; v++) {
                long long dist = x[v] - d;
                int minn = N;
                int pos = lower_bound (x + 1, x + 1 + n, dist) - x;/*
                minn = min (minn, query (1, pos, v - 1).first);
                long long cnt = query (1, pos, v - 1).second;
                if (cnt == 2) ++ res;
                update (1, v, minn);*/
                for (int k = pos; k <= v - 1; k++) {
                    minn = min (minn, mig[u][k].now + 1);
                }
                long long cnt = 0;
                for (int k = pos; k <= v - 1; k++) {
                    if (minn == mig[u][k].now + 1) {
                        cnt += mig[u][k].cnt;
                    }
                }
                if (cnt == 2) ++ res;
                mig[u][v] = {minn, cnt};
            }
        }
        cout << res << "\n";
    }
    return 0;
}
