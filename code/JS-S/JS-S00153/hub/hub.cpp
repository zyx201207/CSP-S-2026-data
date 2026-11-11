#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;

int dis[4005][4005];
vector<int> g[maxn];
vector<int> g2[15];

void dfs(int u,int fa,int rt){
    dis[rt][u]=dis[rt][fa]+1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa)continue;
        dfs(v,u,rt);
    }
}

bool vis[15];
void dfs2(int u,int fa){
    vis[u]=1;
    for(int i=0;i<g2[u].size();i++){
        int v=g2[u][i];
        if(v==fa)continue;
        dfs2(v,u);
    }
}

void solve(){
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        g[i].clear();

    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        dis[i][0]=0;
        dfs(i,0,i);
    }
    if(n<=10){
        int ans=10;
        for(int mask=0;mask<(1<<n);mask++){
            if(__builtin_popcount(mask)!=k)continue;
            int s=mask,idx=1;
            vector<int> cstr;
            while(s){
                if(s&1)cstr.push_back(idx);
                s>>=1;
                idx++;
            }
            for(int i=0;i<k;i++){
                g2[i].clear();
            }
            for(int i=0;i<k;i++)
                for(int j=0;j<g[i].size();j++)
                    for(int m=0;m<k;m++)
                        if(g[cstr[i]][j]==cstr[m])
                            g2[i].push_back(m);
            for(int i=0;i<k;i++)
                vis[i]=0;
            int ans1=0;
            for(int i=0;i<k;i++){
                if(!vis[i]){
                    dfs2(i,-1);
                    ans1++;
                }
            }
            if(ans1>2)continue;
            int ans2=0;
            for(int i=1;i<=n;i++){
                int ans3=10;
                for(int j=0;j<k;j++){
                    ans3=min(ans3,dis[cstr[j]][i]);
                }
                ans2=max(ans3,ans2);
            }
            ans=min(ans,ans2);
        }
        cout<<ans-1<<'\n';
    }
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
