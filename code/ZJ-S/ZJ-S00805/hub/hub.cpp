#include<bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=2000010;
const i64 INF=0x3f3f3f3f3f3f3f3fll;
int n,k;
vector<int>G[N];
int fa[N];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
i64 dis[1010][1010];
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=(i==j?0:INF);
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        dis[u][v]=dis[v][u]=1;
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    int ans=n+1;
    for(int S=0;S<(1<<n);S++){
        if(__builtin_popcount(S)!=k)continue;
        int cnt=0;
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=1;i<=n;i++){
            if(!((S>>(i-1))&1))continue;
            for(auto &v:G[i]){
                if(!((S>>(v-1))&1))continue;
                fa[find(i)]=find(v);
            }
        }
        for(int i=1;i<=n;i++)if((S>>(i-1))&1)cnt+=(find(i)==i);
        if(cnt>2)continue;
        int maxx=0;
        for(int i=1;i<=n;i++){
            i64 mn=INF;
            for(int j=1;j<=n;j++){
                if(!((S>>(j-1))&1))continue;
                mn=min(mn,dis[i][j]);
            }
            maxx=max(maxx,(int)mn);
        }
        ans=min(ans,maxx);
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++)G[i].clear();
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c=0,Tc=1;
    cin>>c>>Tc;
    while(Tc--)solve();
    return 0;
}
/*

*/