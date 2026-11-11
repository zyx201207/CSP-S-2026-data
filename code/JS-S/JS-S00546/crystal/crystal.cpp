#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500010;
const ll INF =1e18;
ll a[N], ans[N], num[N];
struct Node {
    ll num, cnt, cha;
} node[N];

bool cmp(Node x, Node y) {
    return x.cha < y.cha;
}
int chazhi[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int tot = 0;
    int flag = 0, flag2 = 0;
    int guding = a[2] - a[1];
    for (int i = 1; i <= n; i++) {
        if (a[i] != i) flag = 1;
        if (i != n && a[i + 1] - a[i] != guding) flag2 = 0;
    }
    for (int i = 1; i < n; i++) {
        chazhi[i] = a[i + 1] - a[i];
    }
    if (!flag) {
        int ans = 0;
        int sum = 0;
        for (ll i = 1; i < n; i++) {
            sum += chazhi[i] * i;
            if (sum <= m) ans = i + 1;
            else break;
        }
        cout << ans<< endl;
        return 0;
    }
    if (!flag2) {
        int ans = 0;
        int sum = 0;
        for (ll i = 1; i < n; i++) {
            sum += chazhi[i] * i;
            if (sum <= m) ans = i + 1;
            else break;
        }
        cout << ans<< endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        ll c = 0;
        ll tmp = a[i];
        while(i<= n && a[i] == tmp) i++, c++;
        tot++;
        node[tot].num = tmp, node[tot].cnt = c;
        i--;

    }
    for (int i = 1; i <= tot; i++) num[i] = node[i].num;
    for (int step = 1; step <= tot; step++) {
        ll now = num[step];
        for (int i = 1; i <= tot; i++) {
            if (node[i].num > now) node[i].cha = INF;
            else node[i].cha = now - node[i].num;
        }
        if (tot <= 300) sort(node + 1, node + tot + 1, cmp);
        ll sum = 0;
        for (int i = 1; i <= tot; i++) {
            if (sum + node[i].cha * node[i].cnt <= m) {
                sum += node[i].cha * node[i].cnt;
                ans[step] += node[i].cnt;
            }
            else {
                ll ch = m - sum;
                ll chu = ch / node[i].cha;
                ans[step] += chu;
                break;
            }
        }
    }
    ll mx = 1;
    for (int i = 1; i <= tot; i++) {
        mx = max(mx, ans[i]);
    }
    cout << mx << endl;
    return 0;
}
