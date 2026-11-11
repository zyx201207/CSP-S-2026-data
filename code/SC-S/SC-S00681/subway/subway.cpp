#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[500006];
long long w[500006],g[506][506];
vector<long long> t[506];
vector<int> p[506];
vector<pair<int,int>> v[500006];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) g[i][j]=1e18;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i],t[i].resize(k[i]+6),p[i].resize(k[i]+6);
		for(int j=1;j<=k[i];j++) cin>>p[i][j]>>t[i][j],v[p[i][j]].push_back({i,j});
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=k[i];j++) for(auto uu:v[p[i][j]]) g[i][uu.first]=g[uu.first][i]=min(g[i][uu.first],t[i][j]+t[uu.first][uu.second]);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j&&j!=k&&k!=i) g[i][j]=min(g[i][j],g[k][j]+g[i][k]);
	while(q--){
		int x,y;
		cin>>x>>y;
		long long d=1e18;
		for(auto i:v[x]) for(auto j:v[y]) d=min(d,t[i.first][i.second]+t[j.first][j.second]+g[i.first][j.first]);
		cout<<d+w[x]+w[y]<<'\n';
	}
	return 0;
}