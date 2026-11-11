#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=5e5+10;
int c,n,m,d,q;
int a[N];
vector<pair<int,int> > g[N*20];
int dis[N];
void dij(int s){
    memset(dis,0x3f,sizeof dis);
priority_queue<pii,vector<pii >,greater<pii > > q;
dis[s]=0;
q.push({0,s});
while(!q.empty()){
    auto t=q.top();
    q.pop();
    int u=t.second;
    for(auto tt:g[u]){
        int v=tt.first;
        int w=tt.second;
        //cout<<v<<" "<<dis[v]<<" "<<u<<" "<<dis[u]<<endl;
        if(dis[v]>dis[u]+w){
            dis[v]=dis[u]+w;
            q.push({dis[v],v});
        }
    }

}
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
  cin>>c>>n>>m>>d>>q;
  for(int i=1;i<=m;i++){
    cin>>a[i];
  }
  for(int i=1;i<=n;i++){
    int k;
    cin>>k;
    int last=0;
    for(int j=1;j<=k;j++){
        int a1,t;
        cin>>a1>>t;
        g[a1].push_back({a1+i*m,t});
        g[a1+i*m].push_back({a1,t});
        if(j!=1){
            g[last+i*m].push_back({a1+i*m,0});
        g[a1+i*m].push_back({last+i*m,0});
        }
        last=a1;
    }
  }
  while(q--){
    int s,t;
    cin>>s>>t;
    dij(s);
    cout<<dis[t]+a[s]+a[t]<<endl;
  }


  return 0;
}

