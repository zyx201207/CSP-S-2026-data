#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,z[10001],x,y,h[10001],ans=INT_MAX;
int xl[1001][1001],k1[1001];
int zd[1001][1001];
int dz[1001][1001],k2[1001];
void DFS(int a,int sum,int l){
    if(a==y){
        ans=min(ans,sum+zd[a][l]+z[a]);
        return;
    }
    for(int i=1;i<=k2[a];i++){
        int t=dz[a][i];
        for(int j=1;j<=k1[t];j++){
            if(xl[t][j]!=a&&h[xl[t][j]]==0){
                h[xl[t][j]]=1;
                if(l==0) DFS(xl[t][j],sum+z[a]+zd[a][t],t);
                else DFS(xl[t][j],sum+zd[a][l]+zd[a][t],t);
                h[xl[t][j]]=0;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>z[i];
    for(int i=1;i<=n;i++){
        int w;
        cin>>w;
        for(int j=1;j<=w;j++){
            int u,v;
            cin>>u>>v;
            xl[i][++k1[i]]=u;
            zd[u][i]=v;
            dz[u][++k2[u]]=i;
        }
    }
    while(q--){
        for(int i=1;i<=m;i++) h[i]=0;
        ans=INT_MAX;
        cin>>x>>y;
        h[x]=1;
        DFS(x,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}
