/*
Cute Chtholly.
*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define rep(i, l, r) for(ll i = (l); i <= (r); i++)
#define per(i, r, l) for(ll i = (r); i >= (l); i--)
#define fo(i, n) rep(i, 1, n)
using ll = long long;
using pll = pair<ll, ll>;

const ll N = 30, INF = 0x3f3f3f3f3f3f3f3f;
ll tid, T, n, k, u, v, st[N][N], dfn[N], dep[N], tot;
bool vis[N], vis1[N];
vector<ll> e[N];

ll merge(ll x, ll y) {
    return dfn[x] < dfn[y] ? x : y;
}

void dfs(ll x, ll f) {
    dfn[x] = ++tot;
    dep[x] = dep[f] + 1;
    st[dfn[x]][0] = f;
    for(ll to : e[x]) {
        if(to == f) continue;
        dfs(to, x);
    }
}

ll lca(ll x, ll y) {
    if(x == y) return x;
    if((x = dfn[x]) > (y = dfn[y])) swap(x, y);
    ll d = __lg(y - x);
    x++;
    return merge(st[x][d], st[y - (1 << d) + 1][d]);
}

void dfs1(ll x) {
    vis1[x] = 1;
    for(ll to : e[x]) {
        if(vis[to] && !vis1[to]) dfs1(to);
    }
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> tid >> T;
    if(tid == 13 || tid == 14) {
        fo(_, T) {
            cin >> n >> k;
            fo(i, n - 1) {
                cin >> u >> v;
            }
            ll m = n / 2;
            if(k == n) {
                cout << "0\n";
                continue;
            }
            if(k == m) {
                cout << "1\n";
                continue;
            }
            if(k == 1) {
                cout << (m + 1) / 2 + 1 << '\n';
                continue;
            }
            if(m % 4 == 0) {
                cout << (m / 4 - k / 4) + 1 << '\n';
            } else if(m % 4 == 1) {
                cout << (m / 4 - (k - 1) / 4) + 1 << '\n';
            } else if(m % 4 == 2) {
                cout << (m / 4 - (k - 2) / 4) + 1 << '\n';
            } else {
                if(k == 2) cout << m / 4 + 2 << '\n';
                else cout << (m / 4 - (k - 3) / 4) + 1 << '\n';
            }
        }
        return 0;
    }
    if(tid <= 3) {
        fo(_, T) {
            cin >> n >> k;
            fo(i, n - 1) {
                cin >> u >> v;
                e[u].pb(v);
                e[v].pb(u);
            }
            tot = 0;
            fo(i, n) dep[i] = 0;
            dfs(1, 0);
            fo(j, __lg(n)) {
                fo(i, n - (1 << j) + 1) {
                    st[i][j] = merge(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
                }
            }
            ll ans = INF;
            rep(p, 0, (1 << n) - 1) {
                if(__builtin_popcountll(p) != k) continue;
                fo(j, n) {
                    if(p >> j - 1 & 1) vis[j] = 1;
                }
                ll cnt = 0;
                fo(j, n) {
                    if(!vis[j]) continue;
                    if(!vis1[j]) {
                        dfs1(j);
                        cnt++;
                    }
                }
                ll tt = 0;
                if(cnt <= 2) {
                    fo(j, n) {
                        ll cc = INF;
                        fo(d, n) {
                            if(vis[d]) {
                                ll sf = dep[j] + dep[d] - 2 * dep[lca(j, d)];
                                if(sf < cc) cc = sf;
                            }
                        }
                        if(cc > tt) tt = cc;
                    }
                    if(tt < ans) ans = tt;
                }
                fo(j, n) vis[j] = vis1[j] = 0;
            }
            cout << ans << '\n';
            fo(i, n) e[i].clear();
        }        
        return 0;
    }
    fo(_, T) {
        cin >> n >> k;
        fo(i, n - 1) {
            cin >> u >> v;
            e[u].pb(v);
            e[v].pb(u);
        }
        tot = 0;
        fo(i, n) dep[i] = 0;
        dfs(1, 0);
        fo(j, __lg(n)) {
            fo(i, n - (1 << j) + 1) {
                st[i][j] = merge(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
            }
        }
        ll ans = INF;
        fo(xx, n) {
            fo(yy, n) {
                if(xx == yy) continue;
                ll tt = 0;
                fo(i, n) {
                    ll sf1 = dep[i] + dep[xx] - 2 * dep[lca(i, xx)];
                    ll sf2 = dep[i] + dep[yy] - 2 * dep[lca(i, yy)];
                    tt = max(tt, min(sf1, sf2));
                }
                ans = min(ans, tt);
            }
        }
        cout << ans << '\n';
        fo(i, n) e[i].clear();
    }
    return 0;
}

