#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,vis[N],dep[N],fa[N],ans,k;
int u,v,T,c;
vector<int>g[N];
int LCA(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    while(dep[u]!=dep[v])u=fa[u];
    while(u!=v)u=fa[u],v=fa[v];
    return u;
}
void dfs(int u,int f){
    fa[u]=f;dep[u]=dep[f]+1;
    for(auto v:g[u]){
        if(v==f)continue;
        dfs(v,u);
    }
}
int a[20];
int main(){
    freopen("hub1.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>T;
    while(T--){
        memset(dep,0,sizeof(dep));
        memset(fa,0,sizeof(fa));
        ans=INT_MAX;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        for(int i=0;i<(1<<n);i++){
            int cnt=0;
            for(int j=1;j<=n;j++){
                if((i>>(j-1))&1)cnt++;
            }
            if(cnt==k){
                int tmp=0,sum=INT_MAX,ss=0;
                for(int j=1;j<=n;j++){
                    if((i>>(j-1))&1)vis[j]=1;
                }
                for(int j=1;j<=n;j++)if((i>>(j-1))&1)if(vis[fa[j]]==0)tmp++;
                if(tmp<=2){
                    for(int j=1;j<=n;j++){
                        sum=INT_MAX;
                        for(int k=1;k<=n;k++){
                            if((i>>(k-1))&1){
                                sum=min(dep[j]+dep[k]-dep[LCA(j,k)]+1,sum);
                            }
                        }
                        ss=max(ss,sum);
                    }
                }
                for(int j=1;j<=n;j++){
                    if((i>>(j-1))&1)vis[j]=0;
                }
                ans=min(ans,ss);
            }
        }
        cout<<ans<<'\n';
        for(int i=1;i<=n;i++)g[i].clear();
    }
    return 0;
}
