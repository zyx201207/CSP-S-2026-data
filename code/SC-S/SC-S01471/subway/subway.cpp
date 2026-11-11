#include<bits/stdc++.h>
#define pb emplace_back
#define int long long
#define pii  pair<int,int> 
using namespace std;
const int N=5e5+10;
vector<pii>vec[N];
int C,n,m,d,q,f[505][505],w[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	  f[i][j]=1e18;
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int i=1;i<=n;++i){
	  int k,x,y;
	  cin>>k;
	  while(k--){
		cin>>x>>y;
		vec[x].pb(i,y);
	  }
	}
	for(int qwq=1;qwq<=m;++qwq)
	for(int i=0;i<(int)vec[qwq].size();++i)
	for(int j=i+1;j<(int)vec[qwq].size();++j){
	  int x=vec[qwq][i].first,y=vec[qwq][j].first,c=vec[qwq][i].second+vec[qwq][j].second;
	  f[x][y]=min(f[x][y],c);
	  f[y][x]=min(f[y][x],c);
	}
	for(int k=1;k<=n;++k)
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j){
	  if(i==j||i==k||j==k)continue;
	  f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	while(q--){
	  int x,y;
	  cin>>x>>y;
	  int val=1e18;
	  for(pii p:vec[x])
	  for(pii q:vec[y])
		val=min(val,f[p.first][q.first]+p.second+q.second);
	  cout<<w[x]+w[y]+val<<"\n";
	}
	return 0;
}
/*
n<=500，很明显是想让我们写 floyd

把每个线路看成点。

floyd 求出从一个线路走到另一个线路的最短路是多少。

复杂度是 O(md^2 + n^3 + qd^2)，不过这个 md^2 明显卡不满，而且真是这个复杂度也能过吧。

*/