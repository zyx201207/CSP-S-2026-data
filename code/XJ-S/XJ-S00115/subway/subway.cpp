#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10,M = 505;
typedef long long LL;
int c,n,m,d,q;
LL dist[M][M];
vector <int> g[N];
vector <LL> s[N];
LL w[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dist,0x3f,sizeof dist);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            int a;
            LL t;
            cin >> a >> t;
            for(int l = 0;l < g[a].size();l++){
                int v = g[a][l];
                LL len = s[a][l];
                /*if(i > v)   dist[v][i] = min(dist[v][i],t+len);
                else    dist[i][v] = min(dist[i][v],t+len);*/
                dist[v][i] = min(dist[v][i],t+len);
                //cout << v << ' ' << i << ' ' << dist[v][i] << '\n';
            }
            g[a].push_back(i);
            s[a].push_back(t);
        }
        dist[i][i] = 0;
    }
    for(int k = 1;k <= n;k++){
        for(int u = 1;u <= n;u++){
            for(int v = u+1;v <= n;v++){
                if(u >= k)   dist[u][v] = min(dist[u][v],dist[k][u]+dist[k][v]);
                else if(u < k && v >= k) dist[u][v] = min(dist[u][v],dist[u][k]+dist[k][v]);
                else    dist[u][v] = min(dist[u][v],dist[u][k] + dist[v][k]);
            }
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        LL nmin = 1e18;
        for(int i = 0;i < g[x].size();i++){
            for(int j = 0;j < g[y].size();j++){
                int u = g[x][i],v = g[y][j];
                //cout << u << ' ' << v << "-\n";
                LL eu = s[x][i],ev = s[y][j],ans = 0;
                if(u <= v) {
                    ans = eu+ev+dist[u][v]+w[x]+w[y];
                } else {
                    ans = eu+ev+dist[v][u]+w[x]+w[y];
                }
                nmin = min(nmin,ans);
            }
        }
        cout << nmin << '\n';
    }
    return 0;
}