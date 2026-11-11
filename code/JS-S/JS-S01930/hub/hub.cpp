#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define pii pair<int,int>
#define u_mp unordered_map
#define u_st unordered_set
#define prio_q priority_queue
#define ll long long
int n,k;
vector<int>g[1000];
vector<int>pt;
int vis[1000],dis[1000],tp[1000];
void dfs(int u,int fa){
    vis[u]=1;
    for(auto i:g[u]){
        if((vis[i]!=1)&&(tp[i]==1)){
            dfs(i,u);
        }
    }
}
void dfs1(int u,int fa){
    dis[u]=min(dis[u],dis[fa]+1);
    for(auto i:g[u]){
        if(dis[i]>dis[u]+1){
            dfs1(i,u);
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        cin>>n>>k;
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=0;i<(1<<n)-1;i++){
            int d=i;
            pt.clear();
            int cnt=0;
            memset(tp,0,sizeof tp);
            for(int j=1;j<=n;j++){
                if(d&1){
                    cnt++;
                    tp[j]=1;
                    pt.push_back(j);
                }
                d>>=1;
            }
            if(cnt!=k){
                continue;
            }
            cnt=0;
            memset(vis,0,sizeof vis);
            memset(dis,0x3f,sizeof dis);
            for(auto ii:pt){
                if(!vis[ii]){
                    cnt++;
                    dfs(ii,0);
                }
            }
            if(cnt>2){
                continue;
            }
            for(auto ii:pt){
                dis[ii]=0;
                dfs1(ii,0);
            }
            int maxs=0;
            for(int ii=1;ii<=n;ii++){
                maxs=max(dis[ii],maxs);
            }
            ans=min(ans,maxs);
        }
        cout<<ans<<endl;
    }
    return 0;
}