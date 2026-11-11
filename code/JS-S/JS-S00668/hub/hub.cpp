#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10,inf=0x3f3f3f3f;

int c,T,n,k,cnt=0,res=inf;
int head[N],vis[N],col[N];

struct node{
    int from,to,nxt;
}edge[N<<1];

inline void add(const int &u,const int &v){
    edge[++cnt]={u,v,head[u]},head[u]=cnt;
    return ;
}

inline void dfs(int x,int pre){
    col[x]=1;
    for(int i=head[x];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==pre || !vis[v] || col[v]) continue;
        dfs(v,x);
    }
    return ;
}

inline void dfs1(int x,int pre,int tot){
    if(vis[x]){
        res=min(res,tot);
        return ;
    }
    for(int i=head[x];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==pre) continue;
        dfs1(v,x,tot+1);
    }
    return ;
}

inline void solve(){
    cin>>n>>k;
    for(int i=1,u,v;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
    int ans=inf;
    for(int i=0;i<(1<<n);i++){
        if(__builtin_popcount(i)!=k) continue;
        // /**/for(int j=1;j<=n;j++) cout<<((i>>(j-1))&1);
        //     cout<<endl;
        for(int j=1;j<=n;j++) vis[j]=0,col[j]=0;
        for(int j=1;j<=n;j++)
            if((i>>(j-1))&1) vis[j]=1;
        int cnt=0;
        for(int j=1;j<=n;j++)
            if(vis[j] && !col[j]) dfs(j,0),cnt++;
        if(cnt>2) continue;
        for(int j=1;j<=n;j++){
            if(!vis[j]){
                res=inf;
                dfs1(j,0,0);
                ans=min(ans,res);
            }
        }
    }
    cout<<ans<<'\n';
    return ;
}

int main(){
    // freopen("hub.in","r",stdin);
    // freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--) solve();
    return 0;
}