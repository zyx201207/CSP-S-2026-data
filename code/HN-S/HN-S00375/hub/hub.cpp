#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int N=15;
int n,k,ans;
vector<int>g[N];
int choose[N];
int dis[N];
int fa[N];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int check(){
    for(int i=1;i<=n;i++)fa[i]=i,dis[i]=n+1;
    int num=k;
    for(int i=1;i<=n;i++)
        if(choose[i])
            for(int y:g[i])
                if(choose[y]&&find(y)!=find(i))
                    fa[find(y)]=find(i),num--;
    if(num>2)return 1000000;
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(choose[i])q.push(i),dis[i]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:g[u])
            if(dis[v]==n+1)
                dis[v]=dis[u]+1,q.push(v);
    }
    int mx=0;
    for(int i=1;i<=n;i++)mx=max(mx,dis[i]);
    return mx;
}
void dfs(int x,int xk=0){
    if(xk>k)return ;
    if(x>n){
        ans=min(ans,check());
        return ;
    }
    choose[x]=1,dfs(x+1,xk+1);
    choose[x]=0,dfs(x+1,xk);
}
void solve(){
    cin>>n>>k,ans=1000000;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1,u,v;i<n;i++)
        cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
    dfs(1,0);
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--)solve();
}
/*
so cool

how stupid i am
*/

/*
/usr/bin/time -f "time %e S,mxRSS %M kb" ./a
*/