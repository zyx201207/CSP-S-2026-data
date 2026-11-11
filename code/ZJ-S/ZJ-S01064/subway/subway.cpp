#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long> > g[500010];
int w[500010];
long long c,n,m,d,q,i,j,k,x,y,ans,f[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++) cin>>w[i];
	const int N=n,M=m;
	int e[N+10][M+10]={0};
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>x>>y;
			e[x][i]=y;
			g[x].push_back(make_pair(i,y));
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			f[i][j]=1e18;
	for(i=1;i<=n;i++) f[i][i]=0;
	for(i=1;i<=m;i++)
		for(j=0;j<g[i].size();j++)
			for(k=j+1;k<g[i].size();k++){
				f[g[i][j].first][g[i][k].first]=min(f[g[i][j].first][g[i][k].first],g[i][j].second+g[i][k].second);
				f[g[i][k].first][g[i][j].first]=min(f[g[i][k].first][g[i][j].first],g[i][j].second+g[i][k].second);
			}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(i!=j){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
	}
	while(q--){
		cin>>x>>y;
		ans=1e18;
		for(i=0;i<g[x].size();i++)
			for(j=0;j<g[y].size();j++){
				ans=min(ans,f[g[x][i].first][g[y][j].first]+e[x][g[x][i].first]+e[y][g[y][j].first]+w[x]+w[y]);
			}
		cout<<ans<<"\n";
	}
}
