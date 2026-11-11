#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int cs,n,m,d,q,l,A,B;
long long dis[509][509],w[N],W;
vector<pair<int,long long>> g[N];
//n:metro line number
//m:metro station number
//w[]:gate to station
//a[][](x.first):the station on each line
//t[][](x.second):time from station to platform
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&cs,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",w+i);
	for(int i=1;i<=n;i++){
		scanf("%d",&l);
		for(int j=1;j<=l;j++)scanf("%d %lld",&A,&W),g[A].push_back({i,W});
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		int L=g[i].size();
		for(int j=0;j<L;j++)for(int k=0;k<j;k++){
			dis[g[i][j].first][g[i][k].first]=min(dis[g[i][j].first][g[i][k].first],g[i][j].second+g[i][k].second);
			dis[g[i][k].first][g[i][j].first]=min(dis[g[i][k].first][g[i][j].first],g[i][k].second+g[i][j].second);
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)if(i!=k)for(int j=1;j<=n;j++)if(j!=k&&j!=i)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	// cout<<"Debug\n";
	// for(int i=1;i<=n;i++)if(g[i].size()==0)cout<<i<"Debug\n";
	// for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(dis[i][j]>1e16)cout<<i<<" "<<j<<"Debug\n";
	while(q--){
		scanf("%d %d",&A,&B);
		long long res=1e18;
		for(auto a:g[A])for(auto b:g[B])res=min(res,a.second+b.second+dis[a.first][b.first]);
		printf("%lld\n",w[A]+w[B]+res);
	}
}