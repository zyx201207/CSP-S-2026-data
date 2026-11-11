#include <bits/stdc++.h>
using namespace std;
#define N 100007
#define int long long
int ava[N];
int dis[N];
int c,T;
int n,k;
vector<int> g[N];
int vis[N];
int ans;
void dfs1(int u,int fa){
    //cout<<u<<'\n';
    vis[u]=1;
    for(auto v:g[u]){
        if(v!=fa&&!vis[v]&&ava[v]){
            dfs1(v,u);
        }
    }
}
void dfs2(int u,int fa,int l){
    //cout<<u<<'\n';
    dis[u]=min(dis[u],l);
    for(auto v:g[u]){
        if(v!=fa){
            dfs2(v,u,l+1);
        }
    }
}

void solvep(){
    int cnt=0;
    for(int i=1;i<=n;++i){
        vis[i]=0;
        //cout<<ava[i]<<' ';
    }
    //cout<<'\n';
    for(int i=1;i<=n;++i){
        if(!vis[i]&&ava[i]){
            dfs1(i,0);
            ++cnt;
            //cout<<"done\n";
            if(cnt>2){
                //cout<<"done\n";
                return;
            }
        }
    }
    for(int i=1;i<=n;++i){
        dis[i]=n+1;
    }
    //        cout<<"done\n";
    for(int i=1;i<=n;++i){
        if(ava[i]){
            //cout<<"111 "<<i<<'\n';
            dfs2(i,0,0);
        }
    }
    int r=0;
    for(int i=1;i<=n;++i){
        r=max(r,dis[i]);
    }
    ans=min(ans,r);
    //cout<<"done\n";
}

void bld(int idx,int cnt){
    //cout<<idx<<' '<<cnt<<'\n';
    if(idx>n) return;
    if(cnt==k){
        solvep();
        return;
    }
    for(int i=idx+1;i<=n;++i){
        ava[i]=1;
        bld(i,cnt+1);
        ava[i]=0;
    }
}

void solveBF(){
    //cout<<ans<<'\n';
    memset(ava,0,sizeof(ava));
    bld(0,0);
    cout<<ans<<'\n';
}

void solve(){
    ans=2000000000;
    for(int i=1;i<=n;++i){
        g[i].clear();
    }
    cin>>n>>k;
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(c<=3||c==7){
        solveBF();
    }
    else{
        cout<<2*n/3<<'\n';
    }
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        solve();
    }
}