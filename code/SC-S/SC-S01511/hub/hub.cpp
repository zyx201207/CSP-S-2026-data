#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,T;
int n,k;
int ans;
vector<int>road[N];
int S;
int vis[N];
void dfs(int x){
    vis[x]=1;
    for(int v:road[x]){
        if(!vis[v]&&((S>>v)&1)){
            dfs(v);
        }
    }
}
void dfs1(int fa,int x){
    for(int v:road[x]){
        if(v==fa)continue;
        vis[v]=min(vis[v],vis[x]+1);
        dfs1(x,v);
    }
}
int change(){
    int res=0;
    for(int i=1;i<=n;i++){
        if((S>>i)&1){
            vis[i]=0;
            dfs1(0,i);
        }
    }
    for(int i=1;i<=n;i++){
        res=max(res,vis[i]);
    }
    return res;
}
bool check(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]&&((S>>i)&1)){
            cnt++;
            dfs(i);
        }
    }
    return cnt<=2;
}
void solve1(){
    cin>>n>>k;
    if(k==n){
        cout<<0<<'\n';
        return;
    }
    ans=n;
    for(int i=1;i<=n;i++)road[i].clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        road[u].push_back(v);
        road[v].push_back(u);
    }
    int U=(1<<n)-1;
    for(S=0;S<=U;S++){
        if(__builtin_popcount(S)!=k)continue;
        memset(vis,0,sizeof vis);
        if(!check())continue;
        memset(vis,0x3f,sizeof vis);
        ans=min(ans,change());
    }
    cout<<ans<<'\n';
    return;
}
void solve2(){
    cin>>n>>k;
     if(k==n){
        cout<<0<<'\n';
        return;
    }
    ans=n;
    for(int i=1;i<=n;i++)road[i].clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        road[u].push_back(v);
        road[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            memset(vis,0x3f,sizeof vis);
            vis[i]=vis[j]=0;
            queue<int>q;
            q.push(i);
            q.push(j);
            int res=0;
            while(!q.empty()){
                int v=q.front();
                res=max(res,vis[v]);
                if(res>=ans)break;
                q.pop();
                for(int u:road[v]){
                    if(vis[u]>vis[v]+1){
                        vis[u]=vis[v]+1;
                        q.push(u);
                    }
                }
            }
            
            ans=min(ans,res);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        if(c==7)solve2();
        solve1();
    }
    return 0;
}