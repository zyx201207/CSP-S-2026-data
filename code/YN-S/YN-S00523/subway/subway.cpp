#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =1e3+5;
const int INF = -1;
int c,n,m,d,q,w[N];
struct node
{
    int u,t;
};
int g[N][N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
        for(int j=1;j<=m;j++) g[i][j]=INF;
        g[i][i]=0;
    }
    for(int i=1,k;i<=n;i++)
    {
        cin>>k;
        vector<node>l;
        for(int j=1,u,t;j<=k;j++)
        {
            cin>>u>>t;
            l.push_back({u,t});
        }
        for(int j=0;j<k;j++)
        {
            for(int x=j+1;x<k;x++)
            {
                if(g[l[j].u][l[x].u]<0){
                    g[l[j].u][l[x].u]=l[j].t+l[x].t;
                    g[l[x].u][l[j].u]=l[j].t+l[x].t;
                }
                else{
                    g[l[j].u][l[x].u]=min(g[l[j].u][l[x].u],l[j].t+l[x].t);
                    g[l[x].u][l[j].u]=g[l[j].u][l[x].u];
                }
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(g[i][k]<0||g[k][j]<0) continue;
                if(g[i][j]<0){
                        g[i][j]=g[i][k]+g[k][j];
                }
                else g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(int i=1,x,y;i<=q;i++)
    {
        cin>>x>>y;
        cout<<g[x][y]+w[x]+w[y]<<"\n";
    }
    return 0;
}
