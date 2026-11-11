#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;
int C,n,m,d,Q,w[N],dis[510][510];
vector<pair<int,int>> sta[N],ln[510];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int a,s;cin>>a>>s;
            ln[i].push_back({a,s});
            sta[a].push_back({i,s});
        }
    }
    memset(dis,127,sizeof(dis));
    for(int i=1;i<=n;i++){
        for(pair<int,int> ed1:ln[i]){
                int u=ed1.first,w1=ed1.second;
            for(pair<int,int> ed2:sta[u]){
                int v=ed2.first,w2=ed2.second;
                if(v==i) continue;
                dis[i][v]=min(dis[i][v],w1+w2);
            }
        }
    }
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]+dis[k][j]<dis[i][j]&&dis[i][k]+dis[k][j]>0){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    while(Q--){
        int x,y;cin>>x>>y;
        int ans=LONG_LONG_MAX;
        for(pair<int,int> ed1:sta[x]){
            for(pair<int,int> ed2:sta[y]){
                int u=ed1.first,v=ed2.first,w1=ed1.second,w2=ed2.second;
                ans=min(ans,w1+w2+w[x]+w[y]+dis[u][v]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
