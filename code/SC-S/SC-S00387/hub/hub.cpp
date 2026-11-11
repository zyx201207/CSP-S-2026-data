#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int f[N],is[N],dis[N];
int find(int i){
    return f[i]==i?i:f[i]=find(f[i]);
}
int n,k;
vector<int>G[N];
void solve(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v),G[v].push_back(u);
    }
    int ans=n+1;
    for(int i=0;i<(1<<n);i++){
        if(__builtin_popcount(i)!=k)continue;
        for(int j=1;j<=n;j++)f[j]=j,dis[j]=-1,is[j]=((i>>(j-1))&1);
        for(int j=1;j<=n;j++)for(int k:G[j])if(is[j]&&is[k]){
            int ra=find(j),rb=find(k);
            if(ra!=rb)f[ra]=rb;
        }
        int cnt=0,td=0;
        for(int j=1;j<=n;j++)if(is[j]&&find(j)==j)cnt++;
        if(cnt>2)continue;
        queue<int>Q;
        for(int j=1;j<=n;j++)if(is[j])dis[j]=0,Q.push(j);
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            for(int v:G[u]){
                if(dis[v]==-1){
                    dis[v]=dis[u]+1;
                    td=dis[v];
                    Q.push(v);
                }
            }
        }
        ans=min(ans,td);
    }
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++)G[i].clear();
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,T;cin>>c>>T;
    while(T--)solve();
    return 0;
}