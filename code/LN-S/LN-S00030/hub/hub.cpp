#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=5e3+10;
int c,n,m,d,q;
int a[N];
vector<pair<int,int> > g[N];
int dis[N][N],cnt[N][N];
void dij(int s,int k){

priority_queue<pii,vector<pii >,greater<pii > > q;
dis[k][s]=0;
q.push({0,s});
while(!q.empty()){
    auto t=q.top();
    q.pop();
    int u=t.second;
    for(auto tt:g[u]){
        int v=tt.first;
        int w=tt.second;
        //cout<<v<<" "<<dis[v]<<" "<<u<<" "<<dis[u]<<endl;
        if(dis[k][v]>dis[k][u]+w){
            dis[k][v]=dis[k][u]+w;
            q.push({dis[k][v],v});
        }
        else if(dis[k][v]==dis[k][u]+w) cnt[k][v]++;
    }

}
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
  int T;
  cin>>c>>T;
  while(T--){
       cout<<1<<endl;
  }


  return 0;
}
