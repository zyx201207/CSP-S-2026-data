#include<bits/stdc++.h>
using namespace std;
const int maxm=5e5+10;
const int maxn=505;
const long long inf=1e18+10;
int c,n,m,d,q;
long long dis[maxn][maxn],w[maxm];
struct node{
    int x;long long t;
};
vector<node>e[maxm];
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dis[i][j]=inf;
        dis[i][i]=0;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    init();
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int x;long long val;cin>>x>>val;
            for(node y:e[x]){
                int u=y.x;
                dis[i][u]=dis[u][i]=min(dis[u][i],val+y.t);
            }
            e[x].push_back({i,val});
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j || i==k || j==k) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int u,v;cin>>u>>v;
        long long ans=inf;
        for(node i:e[u]){
            for(node j:e[v]){
                ans=min(ans,i.t+j.t+dis[i.x][j.x]);
            }
        }
        ans+=w[u]+w[v];
        cout<<ans<<"\n";
    }
    return 0;
}