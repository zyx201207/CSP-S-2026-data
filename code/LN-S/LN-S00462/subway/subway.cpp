#include<bits/stdc++.h>
using namespace std;
#define N 510
#define M 500010
#define ll long long
ll c,m,n,d,q;
ll f[N][N],w[M],v[N][N];
struct Node{
    int u,d;
};
vector<Node>t[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x;
            cin>>x>>d;
            t[x].push_back({i,d});
        }
    }
    memset(v,0x3f,sizeof v);
    for(int i=1;i<=m;i++){
        for(int j=0;j<t[i].size();j++){
            for(int k=0;k<t[i].size();k++){
                int x=t[i][j].u,y=t[i][k].u;
                d=t[i][j].d+t[i][k].d;
                v[x][y]=min(v[x][y],d);
                v[y][x]=min(v[y][x],d);
                if(x==y){
                    v[x][y]=0;
                    v[y][x]=0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=v[i][j];
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=k&&j!=k)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i!=k&&j!=k)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    */
    while(q--){
        ll ans=0x3f3f3f3f3f3f3f3f;
        int x,y;
        cin>>x>>y;
        for(int i=0;i<t[x].size();i++){
            for(int j=0;j<t[y].size();j++){
                ans=min(ans,f[t[x][i].u][t[y][j].u]+t[x][i].d+t[y][j].d);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
