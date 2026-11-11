#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
ll n, m, cnt;
ll a[N], lst[N], nxt[N];
ll vis[N], num[N], ans[N];
struct Node {
    ll l, r;
} pos[N];
bool cmp(Node x, Node y) {
    return x.l < y.l;
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;++i) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;++i) {
        if(!lst[a[i]]) {
            lst[a[i]] = i;
        } else {
            pos[++cnt].l = lst[a[i]];
            vis[lst[a[i]]] = cnt;
            pos[cnt].r = i;
            lst[a[i]] = i;
        }
    }
    sort(pos + 1, pos + cnt + 1, cmp);
    for(int i = 1;i <= n;++i) {
        ll j = i;
        for(int k = 1;k <= m;++k) num[k] = 0;
        while(j <= n) {
            while(vis[j]) {
                while(vis[j]) j = pos[vis[j]].r;
                num[a[j]]++;
                ++j;
                if(j > n) break;
            }
            num[a[j]]++;
            ++j;

        }
        for(int k = 1;k <= m;++k) {
            if(num[k]) ++ans[k];
        }
    }
    for(int i = 1;i <= m;++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
