#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using PII = pair <int,int>;
using LL = long long;
using ULL = unsigned long long;
template <typename T1,typename T2> void tomax (T1 &x,T2 y) {if (y > x) x = y;}
template <typename T1,typename T2> void tomin (T1 &x,T2 y) {if (y < x) x = y;}
#define pb push_back
const int N = 20;
int n,k;
vector <int> g[N];
int p[N];
int dist[N];
int find (int x) {
    return p[x] == x ? x : p[x] = find (p[x]);
}
void mian () {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) g[i].clear ();
    for (int i = 1;i <= n - 1;i++) {
        int a,b;
        cin >> a >> b;
        g[a].pb (b),g[b].pb (a);
    }
    if (n <= 10) {
        int ans = 1e9;
        for (int s = 0;s < 1 << n;s++) {
            if (__builtin_popcount (s) != k) continue;
            for (int i = 1;i <= n;i++) p[i] = i;
            for (int i = 1;i <= n;i++) {
                if (!(s >> i - 1 & 1)) continue;
                for (int j : g[i]) {
                    if (!(s >> j - 1 & 1)) continue;
                    p[find (i)] = find (j);
                }
            }
            int cnt = 0;
            for (int i = 1;i <= n;i++) {
                if (s >> i - 1 & 1) cnt += find (i) == i;
            }
            if (cnt > 2) continue;
            for (int i = 1;i <= n;i++) dist[i] = -1;
            queue <int> q;
            for (int i = 1;i <= n;i++) {
                if (s >> i - 1 & 1) dist[i] = 0;
                q.push (i);
            }
            while (q.size ()) {
                int u = q.front ();
                q.pop ();
                for (int v : g[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push (v);
                    }
                }
            }
            int res = 0;
            for (int i = 1;i <= n;i++) tomax (res,dist[i]);
            tomin (ans,res);
        }
        cout << ans << endl;
        return ;
    }
}
int main () {
    freopen ("hub.in","r",stdin);
    freopen ("hub.out","w",stdout);
    int T = 1;
    cin >> T >> T;
    while (T--) mian ();
    return 0;
}