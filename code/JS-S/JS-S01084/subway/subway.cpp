#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(int i = a; i <= b; i++)
#define For2(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 501;
const ll inf = 9e18;
inline int read() {
    int x = 0,fl = 1; char c = getchar();
    while (!isdigit(c)) {{if (c == '-') fl = -1;}c = getchar();}
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * fl;
}
int c,n,m,d,q,w[N],K[N],cnt[N];
vector<int> a[N],t[N];
int id1[N][21],id2[N][N],id3[N][N];
ll dis[N][N][21];
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c = read(); n = read(); m = read(); d = read(); q = read();
    For (i,1,m) w[i] = read();
    For (i,1,n) {
        K[i] = read();
        a[i].resize(K[i]+1,0); t[i].resize(K[i]+1,0);
        For (j,1,K[i]) {
            a[i][j] = read();
            t[i][j] = read();
            cnt[a[i][j]]++;
            id1[a[i][j]][cnt[a[i][j]]] = i;
            id2[i][a[i][j]] = cnt[a[i][j]];
            id3[a[i][j]][i] = j;
        }
    }

    For (i,1,m) {
        For (j,i,m) {
            if (i == j) {
                For (id,1,cnt[j]) {
                    int pos = id1[i][id];
                    dis[i][i][id] = w[i] + t[pos][id3[i][pos]];
                }
            }else For (id,1,cnt[j]) dis[i][j][id] = inf;
        }
        priority_queue<pair<ll,int>> q;
        For (id,1,cnt[i]) {
            q.push({-dis[i][i][id],i*(d+1)+id});
        }
        bool vis[N][21];
        For (j,1,n) {
            For (id,1,cnt[j]) vis[j][id] = false;
        }
        while (!q.empty()) {
            pair<ll,int> tmp = q.top(); q.pop();
            int id_u = tmp.second % (d + 1);
            int u = tmp.second / (d+1) ,k = id1[u][id_u];

            if (vis[u][id_u]) continue;
            vis[u][id_u] = true;

            For (id,1,cnt[u]) {
                int real = id1[u][id];
                For (j,1,K[real]) {
                    int v = a[real][j];
                    if (v == u) continue;
                    if (real == k) {
                        if (dis[i][u][id_u] < dis[i][v][id2[real][v]]) {
                            dis[i][v][id2[real][v]] = dis[i][u][id_u];
                            q.push({-dis[i][v][id2[real][v]],v*(d+1)+id2[real][v]});
                        }
                    }
                    else if (dis[i][u][id_u] + t[real][id2[real][v]] + t[k][id2[k][v]] < dis[i][v][id2[real][v]]) {
                        int pos = id1[v][id];
                        dis[i][v][id2[real][v]] = dis[i][u][id_u] + t[real][id2[real][v]] + t[k][id2[k][v]];
                        q.push({-dis[i][v][id2[real][v]],v*(d+1)+id2[real][v]});
                    }
                }
            }
            //cout << 1 << endl;
        }
    }
    while (q--) {
        int x = read(),y = read();
        ll ans = inf;
        For (i,1,cnt[y]) {
            int pos = id1[y][i];
            ans = min(ans,dis[x][y][i] + t[pos][id3[y][pos]] + w[y]);
        }
        cout << ans << endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7

*/
