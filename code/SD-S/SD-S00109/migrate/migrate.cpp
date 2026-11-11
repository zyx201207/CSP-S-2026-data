/*
Cute Chtholly.
==
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

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

const ll N = 2e6 + 5, INF = 0x3f3f3f3f3f3f3f3f;
ll tid, T, n, d, a[N], nxt[N], pre[N];
ll dis[N], cnt[N], cnt1[N];
priority_queue<pll, vector<pll>, greater<pll>> q;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> tid >> T;
    if(tid <= 10) {
        fo(_, T) {
            cin >> n >> d;
            fo(i, n) {
                cin >> a[i];
            }
            if(n == 1) {
                cout << "0\n";
                continue;
            }
            ll ans = 0;
            fo(i, n) {
                rep(j, 0, n) dis[j] = cnt1[j] = cnt[j] = 0;
                dis[i] = 0, cnt[i] = 1;
                while(q.size()) q.pop();
                q.push({dis[i], i});
                cnt1[0] += cnt[i];
                for(ll j = i + 1, f = i; j <= n; j++) {
                    while(a[f] < a[j] - d) {                
                        cnt1[dis[f]] -= cnt[f];
                        f++;
                    }
                    dis[j] = dis[f] + 1;
                    cnt[j] = cnt1[dis[f]];
                    if(cnt[j] == 2) ans++;
                    q.push({dis[j], j});
                    cnt1[dis[j]] += cnt[j];
                    if(cnt1[dis[j]] > INF) cnt1[dis[j]] = INF;
                }
            }
            cout << ans << '\n';
        }
        return 0;
    }
    if(tid == 11 || tid == 12) {
        fo(_, T) {
            cin >> n >> d;
            fo(i, n) {
                cin >> a[i];
            }
            if(n == 1) {
                cout << "0\n";
                continue;
            }
            rep(j, 0, n) dis[j] = cnt1[j] = cnt[j] = 0;
            dis[1] = 0, cnt[1] = 1;
            while(q.size()) q.pop();
            q.push({0, 1});
            cnt1[0] += cnt[1];
            rep(j, 2, n) {
                while(q.size() && a[q.top().se] < a[j] - d) {                
                    cnt1[q.top().fi] -= cnt[q.top().se];
                    q.pop();
                }
                dis[j] = q.top().fi + 1;
                cnt[j] = cnt1[q.top().fi];
                q.push({dis[j], j});
                cnt1[dis[j]] += cnt[j];
                if(cnt1[dis[j]] > INF) cnt1[dis[j]] = INF;
            }
            ll zzh = -1ll;
            fo(j, n) {
                if(cnt[j] == 2) zzh = j;
            }
            if(!~zzh) cout << "0\n";
            else cout << n - zzh + 1 << '\n';
        }
        return 0;
    }
    if(tid == 13 || tid == 14) {
        fo(_, T) {
            cin >> n >> d;
            for(ll i = 1, j = 1; i <= n; i++) {
                while(j < n && a[j + 1] - a[i] <= d) j++;
                nxt[i] = j;
            }
            for(ll i = n, j = n; i; i--) {
                while(j > 1 && a[i] - a[j - 1] <= d) j--;
                pre[i] = j;
            }
            ll pos = 0;
            fo(i, n) {
                if(a[i] - a[1] <= d && a[n] - a[i] <= d) {
                    pos = i;
                    break;
                }
            }
            ll cl = 0, cr = 0;
            fo(i, n) {
                if(nxt[i] == pos) cl++;
                if(pre[i] == pos) cr++;
            }
            cout << cl * cr << '\n';
        }
        return 0;
    }
    return 0;
}

