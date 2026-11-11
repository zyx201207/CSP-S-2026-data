#include<bits/stdc++.h>
using namespace std;
#define int long long
#define llg long long
#define sig signed
#define usg unsigned
#define ull unsigned long long
int c,t,n,k;
vector<int>g[1000005];
int is[15],vis[15],dis[15];
void dfs1(int x){
    vis[x]=1;
    for(int i=0;i<g[x].size();++i){
        int u=g[x][i];
        if(is[u]&&!vis[u])dfs1(u);
    }
}
void dfs2(int x){
    if(is[x])dis[x]=0;
    for(int i=0;i<g[x].size();++i){
        int u=g[x][i];
        if(!is[u]&&dis[u]>dis[x]+1){
            dis[u]=dis[x]+1;
            dfs2(u);
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;++i)g[i].clear();
        for(int i=1;i<n;++i){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if(n==k){
            cout<<"0\n";
        }else if(c<=3){
            int ans=n+1;
            for(int i=1;i<(1<<n);++i){
                int cnt=0,rt=0,num=0;
                for(int j=1;j<=n;++j){
                    vis[j]=0;
                    dis[j]=n;
                    if(i>>(j-1)&1){
                        is[j]=1;
                        ++num;
                    }else is[j]=0;
                }
                for(int j=1;j<=n;++j){
                    if(is[j]&&!~vis[j])dfs1(j),++cnt;
                }
                for(int j=1;j<=n;++j){
                    if(is[j])dfs2(j);
                }
                for(int j=1;j<=n;++j)rt=max(rt,dis[j]);
                if(num==k&&cnt<=2)ans=min(ans,rt);
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
