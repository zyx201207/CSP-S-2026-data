#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+7;
ll c,n,m,d,Q,ans,w[N],k[N],T[507][N],a[507][N];
ll Flo[1007][25],cnt[1007],dis[500007];
vector<pair<ll,ll> >G[500007];
priority_queue<pair<ll,ll> >q;
bool vis[500007];
bool flag[507];
void dfs(int s,int f,int t,ll res){
    if(res+T[f][t]>=ans)return;
    if(s==t){
        ans=min(ans,res+T[f][t]);
        return;
    }
    if(!flag[f]){
        flag[f]=true;
        for(int i=1;i<=k[f];i++)dfs(a[f][i],f,t,res);
        flag[f]=false;
    }
    for(int i=1;i<=n;i++)if(!flag[i] && i!=f && T[f][s] && T[i][s])dfs(s,i,t,res+T[f][s]+T[i][s]);
}
void Dij(){
    for(int i=0;i<=n*m;i++)dis[i]=1e18,vis[i]=0;
    dis[0]=0;q.push({0,0});
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<G[u].size();i++){
            ll v=G[u][i].first,w=G[u][i].second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({-dis[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>T[i][a[i][j]];
        }
    }
    if(n<=50){
        while(Q--){
            ll x,y;
            ans=1e18;
            cin>>x>>y;
            for(int i=1;i<=n;i++)
                if(T[i][x])dfs(x,i,y,T[i][x]);
            cout<<ans+w[x]+w[y]<<"\n";
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(k[i]==2){G[a[i][1]+(i-1)*m].push_back({a[i][2]+(i-1)*m,0});
                G[a[i][2]+(i-1)*m].push_back({a[i][1]+(i-1)*m,0});}
            for(int j=1;j<=k[i];j++)
                Flo[a[i][j]][++cnt[a[i][j]]]=i;
        }
        for(int i=1;i<=m;i++)
            for(int j=1;j<cnt[i];j++)
                for(int k=j+1;k<=cnt[i];k++)
                {
                    G[i+(Flo[i][j]-1)*m].push_back({i+(Flo[i][k]-1)*m,T[Flo[i][j]][i]+T[Flo[i][k]][i]});
                    G[i+(Flo[i][k]-1)*m].push_back({i+(Flo[i][j]-1)*m,T[Flo[i][j]][i]+T[Flo[i][k]][i]});
                }
        while(Q--){
            ll x,y;
            ans=1e18;
            cin>>x>>y;
            for(int i=1;i<=n;i++)G[0].push_back({(i-1)*m+x,T[i][x]});
            Dij();
            for(int i=1;i<=n;i++)
                ans=min(ans,dis[(i-1)*m+y]+T[i][y]+w[x]+w[y]);
            G[0].clear();
            cout<<ans<<"\n";
        }
    }
    return 0;
}
