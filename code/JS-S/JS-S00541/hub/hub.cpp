#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int c,t,ans;
int n,k,uu,vv;
bool f[MAXN],vis[MAXN];
int dis[MAXN];
vector<int> son[MAXN];
void dfs(int u){
    vis[u]=1;
    for(int v:son[u])
        if(f[v]&&!vis[v])
            dfs(v);
}
void dfs2(int u){
    for(int v:son[u])
        if(dis[u]+1<dis[v]){
            dis[v]=dis[u]+1;
            dfs2(v);
        }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)son[i].clear();
        for(int i=1;i<n;i++){
            cin>>uu>>vv;
            son[uu].push_back(vv);
            son[vv].push_back(uu);
        }
        ans=MAXN;
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++)
                if((i>>j)&1)
                    f[j+1]=1;
                else f[j+1]=0;
            int tmp=0;
            for(int j=1;j<=n;j++)
                if(f[j])
                    tmp++;
            if(tmp!=k)continue;
            tmp=0;
            for(int j=1;j<=n;j++)vis[j]=0;
            for(int j=1;j<=n;j++)if(f[j]&&!vis[j]){
                dfs(j);
                tmp++;
            }
            if(tmp>2)continue;
            for(int j=1;j<=n;j++)dis[j]=MAXN;
            for(int j=1;j<=n;j++)if(f[j])dis[j]=0;
            for(int j=1;j<=n;j++)if(f[j])dfs2(j);
            int tans=0;
            for(int j=1;j<=n;j++)tans=max(tans,dis[j]);
            ans=min(ans,tans);
            //for(int j=1;j<=n;j++)if(f[j])cout<<j<<' ';
            //cout<<'\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//g++ hub.cpp -o hub -std=c++14 -O2 -static -Wall -Wextra -Wshadow
//ulimit -v
//ulimit -s
//time ./hub
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net
//www.playlinkd.net