#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5,D=25;
const ll INF=2e18;
int c,n,m,d,q,k[N],cnt[M],ps[M][D];
ll ans,w[M],e[N][N];
map<int,ll> cst[M];
ll getres(int sta,int lin){
	return cst[sta][lin];
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
	  cin>>k[i];
	  for(int j=1;j<=k[i];j++){
	    int v1; ll v2; cin>>v1>>v2;
	    ps[v1][++cnt[v1]]=i,cst[v1][i]=v2;
	  }
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    if(j!=i) e[i][j]=INF;
	for(int i=1;i<=m;i++){
	  for(int j=1;j<=cnt[i];j++)
	    for(int k=j+1;k<=cnt[i];k++)
	      e[ps[i][j]][ps[i][k]]=min(e[ps[i][j]][ps[i][k]],cst[i][ps[i][j]]+cst[i][ps[i][k]]),e[ps[i][k]][ps[i][j]]=e[ps[i][j]][ps[i][k]];
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    for(int k=1;k<=n;k++)
	      e[j][k]=min(e[j][k],e[j][i]+e[i][k]);
	while(q--){
	  int x,y; cin>>x>>y;
	  ans=INF;
	  for(int i=1;i<=cnt[x];i++)
	    for(int j=1;j<=cnt[y];j++)
	      ans=min(ans,e[ps[x][i]][ps[y][j]]+cst[x][ps[x][i]]+cst[y][ps[y][j]]);
	  cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}