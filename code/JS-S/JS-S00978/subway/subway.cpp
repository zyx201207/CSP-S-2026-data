#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans,k;
int vis[500050],w[500050],a[500050],t[500050];
struct node{
    int v,s;
};
vector<node> p[500050];
void dfs(int u,int v,int sep){
    if(u==v){
        ans=min(ans,sep);
    }
    for(int i=0;i<p[u].size();i++){
        if(vis[p[u][i].v]==0){
            vis[p[u][i].v]=1;
            dfs(p[u][i].v,v,sep+p[u][i].s);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
            if(j>1)p[a[j-1]].push_back({a[j],t[j-1]+t[j]});
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ans=INT_MAX;
        memset(vis,0,sizeof vis);
        dfs(x,y,0);
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
