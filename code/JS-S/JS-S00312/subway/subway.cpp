#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e4+10;
int c,m,n,d,q;
int w[N],k[505],dist[5005][5005];
bool vis[M];
struct sub{
    int a,t;
}s[N][25];
void floyd(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=m;i++) dist[i][i]=0;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>s[i][j].a>>s[i][j].t;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            if(j>1){
                int u=s[i][j-1].a,v=s[i][j].a;
                dist[u][v]=min(dist[u][v],s[i][j-1].t+s[i][j].t);
            }
            for(int x=1;x<=n&&(x!=i);x++){
                for(int y=1;y<=k[x];y++){
                    if(s[i][j].a==s[x][y].a){
                        dist[s[x][y].a][s[x][y+1].a]+=s[i][j].t;
                    }
                }
            }
        }
    }
    floyd();
    while(q--){
        int u,v;
        cin>>u>>v;
        long long sum;
        sum=w[u]+w[v]+dist[u][v];
        cout<<sum<<'\n';
    }
    return 0;
}
