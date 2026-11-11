#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;
int c,t,n,k,u,v,ans,res,fa[N],tmp,dis[N];
basic_string<int>e[N];
int find(int x){return fa[x]?(fa[x]=find(fa[x])):x;}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x!=y)fa[x]=y;
}
void dfs(int u,int f,int d){
    dis[u]=min(dis[u],d);
    for(int v:e[u])if(v!=f)dfs(v,u,d+1);
}
int main(){
    freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> k,ans=INT_MAX;
        for(int i=1;i<=n;i++)e[i].clear();
        for(int i=1;i<n;i++)cin >> u >> v,e[u]+=v,e[v]+=u;
        for(int i=1;i<(1<<n);i++){
            if(__builtin_popcount(i)!=k)continue;
            memset(fa,0,n<<3|8),tmp=0,res=0;
            for(int j=1;j<=n;j++)if(i&(1<<(j-1)))for(int v:e[j])if(i&(1<<(v-1)))merge(v,j);
            for(int j=1;j<=n;j++)if(i&(1<<(j-1)))if(!fa[j])tmp++;
            if(tmp>2)continue;
            memset(dis,0x3f,n<<3|8);
            for(int j=1;j<=n;j++)if(i&(1<<(j-1)))dfs(j,0,0);
            for(int j=1;j<=n;j++)res=max(res,dis[j]);
            ans=min(ans,res);
        }
        cout << ans << '\n';
    }
    return 0;
}