#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=5e3+10;
int c,n,m,d,q;
int a[N];
vector<pair<int,int> > g[N];
int dis[N][N],cnt[N][N];
bool flag[N];
void dij(int s,int k){
memset(flag,0,sizeof flag);
priority_queue<pii,vector<pii >,greater<pii > > q;
dis[k][s]=0;
q.push({0,s});
while(!q.empty()){
    auto t=q.top();
    q.pop();
    int u=t.second;
    if(flag[u]) continue;
    flag[u]=1;
    for(auto tt:g[u]){
        int v=tt.first;
        int w=tt.second;
        //cout<<v<<" "<<dis[v]<<" "<<u<<" "<<dis[u]<<endl;
        if(dis[k][v]>dis[k][u]+w){
            dis[k][v]=dis[k][u]+w;
            cnt[k][v]=0;
            q.push({dis[k][v],v});
        }
        else if(dis[k][v]==dis[k][u]+w) cnt[k][v]++;
    }

}
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
  int T;
  cin>>c>>T;
  while(T--){

        memset(cnt,0,sizeof cnt);
        memset(dis,0x3f,sizeof dis);
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
  g[i].clear();
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i==j) continue;
            //cout<<(abs(a[i]-a[j])<=d)<<" ";
            if(a[j]-a[i]<=d){
                g[i].push_back({j,1});
                g[j].push_back({i,1});
                //cout<<g[5].size()<<" "<<i<<" "<<j<<endl;
            }
        }
       //cout<<endl;
    }
    int ans=0;
    for(int i=1;i<=n;i++) dij(i,i);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i==j) continue;
            if(cnt[i][j]==1) ans++;
        }
    }
    cout<<ans<<endl;
  }


  return 0;
}


