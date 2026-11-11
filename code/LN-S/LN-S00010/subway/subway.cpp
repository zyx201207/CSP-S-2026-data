#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int c,m,n,d,q,kkk[N];
int p[510],roads[510];//roads为i线路数
int g[510][510],road[N][510],route[510][21];//route为i经过的线路,road为第k条线过i的时间
bool onroad[510][N],on_road[N][510];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>p[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>kkk[i];
        for(int j = 1;j<=kkk[i];j++){
            int to,t;
            cin>>to>>t;
            road[i][to] = t+p[to];
            roads[to]++;
            onroad[to][i] = 1;
            on_road[i][to] = 1;
            route[to][roads[to]] = i;
        }
    }
    for(int i = 1;i<=m;i++){
        for(int j = i+1;j<=m;j++){
            for(int pp = 1;pp<=roads[i];pp++){
                int k = route[i][pp];
                if(onroad[i][k] && onroad[j][k]){
                    if(g[i][j]!=0) g[i][j] = min(g[i][j],road[k][i]+road[k][j]);
                    else g[i][j] = road[k][i]+road[k][j];
                }
            }
        }
    }
    for(int i = 1;i<=m;i++){
        for(int j = i+1;j<=m;j++){
            for(int kkkk = 1;kkkk<=m;kkkk++){
                if(kkkk == j || kkkk == i) continue;
                if(g[i][kkkk]!=0 && g[min(kkkk,j)][max(j,kkkk)] !=0){
                    if(g[i][j]!=0) g[i][j] = min(g[i][j],g[i][kkkk]+g[min(kkkk,j)][max(j,kkkk)]);
                    else g[i][j] = g[i][kkkk]+g[min(kkkk,j)][max(j,kkkk)];
                }
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<g[min(u,v)][max(u,v)];
    }
}
