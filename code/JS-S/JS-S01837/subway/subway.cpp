#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF ((int)(4e18))
#define PII pair<int,int>
#define range(i,x,y) for(int i=x;i<y;++i)
#define in(x,a) for(auto x:a)
using namespace std;

signed main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0),cout.tie(0);
  int c,n,m,d,q;
  scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
  vector<int> w(m+1);
  vector<vector<int>> rail(m+1,vector<int>(n+1,INF));
  vector<vector<int>> dis(n+1,vector<int>(n+1,INF));
  range(i,1,m+1){
    scanf("%lld",&w[i]);
  }
  vector<vector<PII>> sta(n+1);
  range(i,1,n+1){
    int k;
    scanf("%lld",&k);
    sta[i].reserve(k);
    while(k--){
      int u,t;
      scanf("%lld%lld",&u,&t);
      sta[i].emplace_back(u,t);
      rail[u][i]=t;
    }
  }
  range(i,1,n+1){
    dis[i][i]=0;
  }
  range(i,1,n){
    range(j,i+1,n+1){
      in(&t,sta[i]){
        int u=t.first,t1=t.second;
        dis[i][j]=min(dis[i][j],t1+rail[u][j]);
      }
      dis[j][i]=dis[i][j];
    }
  }
  range(k,1,n+1){
    range(i,1,n){
      if(k==i)
        continue;
      range(j,i+1,n+1){
        if(k==j)
          continue;
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        dis[j][i]=dis[i][j];
      }
    }
  }
  while(q--){
    int x,y;
    scanf("%lld%lld",&x,&y);
    int add=w[x]+w[y];
    int d=INF;
    range(i,1,n+1){
      range(j,1,n+1){
        d=min(d,dis[i][j]+rail[x][i]+rail[y][j]);
      }
    }
    printf("%lld\n",d+add);
  }
  return 0;
}