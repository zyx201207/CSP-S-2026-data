#include<bits/stdc++.h>
#define int long long
using namespace std;using P=pair<int,int>;const int N=505,M=5e5+5,inf=1e18;
int n,m,D,q,w[M],d[N][N];vector<P> v[M];
inline void chkmin(int i,int j,int w){d[i][j]=d[j][i]=min(d[i][j],w);}
signed main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _c;cin>>_c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){int a,t;cin>>a>>t,v[a].emplace_back(P{i,t});}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=m;i++){
		int s=v[i].size();
		for(int j=0;j<s;j++)for(int k=j+1;k<s;k++)chkmin(v[i][j].first,v[i][k].first,v[i][j].second+v[i][k].second);
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--){
		int x,y;cin>>x>>y;int ans=inf;
		for(int i=0;i<(int)v[x].size();i++)for(int j=0;j<(int)v[y].size();j++)
			ans=min(ans,v[x][i].second+v[y][j].second+d[v[x][i].first][v[y][j].first]);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}