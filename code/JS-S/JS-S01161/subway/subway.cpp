#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define xian first
#define time second
const int N = 5e5 + 5;
int c,n,m,d,q;
int w[N],k[N],u,v,val;
int dis[505][505];
vector<pii > zhan[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) dis[i][j]=1e18;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        dis[i][i]=0;
        int a,t;
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            zhan[a].emplace_back(i,t);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<zhan[i].size()-1;j++){
            for(int k=j+1;k<zhan[i].size();k++){
                u=zhan[i][j].xian;
                v=zhan[i][k].xian;
                val=zhan[i][j].time+zhan[i][k].time;
                dis[u][v]=min(dis[u][v],val);
                dis[v][u]=min(dis[v][u],val);
            }
        }
    }
   // priority_queue<pii,vector<pii>,greater<pii> >q1;
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
            if(i==j||j==k||i==k) continue;
            if(dis[k][j]>dis[k][i]+dis[i][j]){
                dis[k][j]=dis[k][i]+dis[i][j];
            }
        }
    }
   }
    while(q--){
        int ans=1e18;
        cin>>u>>v;
        for(int i=0;i<zhan[u].size();i++){
            for(int j=0;j<zhan[v].size();j++){
                ans=min(ans,dis[zhan[u][i].xian][zhan[v][j].xian]+zhan[u][i].time+zhan[v][j].time);
            }
        }
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}
