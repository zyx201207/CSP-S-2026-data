#include<bits/stdc++.h>
using namespace std;
vector<int>g[1919810];
int d[1919810],f[1919810],son[1919810],vis[1919810];
vector<int>diam;
void dfs(int u,int fa){
    d[u]=d[fa]+1,f[u]=fa;
    for(int v:g[u])if(v!=fa)dfs(v,u);
}
void loves(){
    int n,x;
    cin>>n>>x;
    for(int i=1,x,y;i<n;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
    memset(d,0,sizeof d),dfs(1,0);
    int maxi,maxd=0;
    for(int i=1;i<=n;i++)if(maxd<=d[i])maxd=d[i],maxi=i;
    memset(d,0,sizeof d),dfs(maxi,0);
    int l=maxi,r,dd=0;
    for(int i=1;i<=n;i++)if(dd<=d[i])dd=d[i],r=i;
    diam.clear();
    memset(vis,0,sizeof vis);
    for(int i=r;i;i=f[i])diam.push_back(i),son[f[i]]=i;
    int rr=1,ll=diam.size()-2;
    while(rr!=ll&&x>=2)vis[rr]++,vis[ll]++,rr=f[rr],ll=son[ll],x-=2;
    if(x==1)vis[rr]++,rr=f[rr];
    int minn=INT_MAX;
    for(int i=1;i<=n;i++)if(vis[i])minn=min(minn,d[i]);
    cout<<minn<<endl;
}
main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)loves();
}
