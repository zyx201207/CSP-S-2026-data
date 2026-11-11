#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d1,q,w[500001],k,u,v,d[501][501],ans;
vector<long long> f[500001][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d1>>q;
	for(long long i=1;i<=m;i++)
		cin>>w[i];
	for(long long i=1;i<=n;i++){
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>u>>v;
			f[u][0].push_back(i);
			f[u][1].push_back(v);
		}
	}
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
			if(i!=j) d[i][j]=1e18;
	for(long long i=1;i<=m;i++)
		for(long long x=0;x<f[i][0].size();x++)
			for(long long y=0;y<f[i][0].size();y++)
				if(x!=y) d[f[i][0][x]][f[i][0][y]]=min(d[f[i][0][x]][f[i][0][y]],f[i][1][x]+f[i][1][y]);
	for(long long i=1;i<=n;i++)
		for(long long x=1;x<=n;x++)
			for(long long y=1;y<=n;y++)
				d[x][y]=min(d[x][y],d[x][i]+d[i][y]);
	for(long long i=1;i<=q;i++){
		cin>>u>>v;
		ans=1e18;
		for(long long x=0;x<f[u][0].size();x++)
			for(long long y=0;y<f[v][0].size();y++)
				ans=min(ans,w[u]+w[v]+f[u][1][x]+f[v][1][y]+d[f[u][0][x]][f[v][0][y]]);
		cout<<ans<<endl;
	}
	return 0;
}
