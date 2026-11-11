#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,k,ans,a[1000005];
vector<int> g[1000005];
int vis[1000005],viss[1000005];
void  dfs1(int now,int dep){
    if(vis[now]<dep){
        return;
    }
    vis[now]=dep;
    for(int x:g[now]){
        vis[x]=min(vis[x],dep+1);
        dfs1(x,dep+1);
    }
}
void  dfs2(int now,int k){
    for(int x:g[now]){
        if(vis[x]==0&&viss[x]==0){
            viss[x]=k;
            dfs2(x,k);
        }
    }
}
int check(){
    memset(vis,0x3f,sizeof(vis));
    for(int i=1;i<=k;i++){
        vis[a[i]]=0;
    }
    viss[a[1]]=1;
    dfs2(a[1],1);
    int cnt=1;
    for(int i=1;i<=k;i++){
        if(viss[a[i]]==0){
            cnt++;
            dfs2(a[i],cnt);
        }
        if(cnt>2){
            return 1e9;
        }
    }
    for(int i=1;i<=k;i++){
        dfs1(a[i],0);
    }
    int Max=0;
    for(int i=1;i<=n;i++){
        Max=max(Max,vis[i]);
    }
    return Max;
}
void dfs(int dep,int now){
    if(dep==k){
        ans=min(ans,check());
        return;
    }
    dep++;
    for(int i=now+1;i<=n;i++){
        a[dep]=i;
        dfs(dep,i);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        ans=1e9+7;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0,0);
        cout<<ans<<endl;
    }
    return 0;
}
