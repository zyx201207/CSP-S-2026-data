#include <bits/stdc++.h>
using namespace std;
int ot,n,m,k,q,A[500010];
vector<pair<int,int>> g[500010];
long long f[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>ot>>n>>m>>k>>q;
	for(int i=1;i<=m;i++)
		cin>>A[i];
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		while(t--){
			int x,y;
			cin>>x>>y;
			g[x].push_back(make_pair(i,y));
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int t=1;t<=m;t++){
		int l=g[t].size();
		for(int i=1;i<l;i++)
			for(int j=0;j<i;j++){
				int x=g[t][i].first,y=g[t][j].first;
				f[x][y]=f[y][x]=min(f[x][y],(long long)g[t][i].second+g[t][j].second);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		long long s=f[0][0];
		for(auto a1:g[x])
		for(auto a2:g[y])
			s=min(s,f[a1.first][a2.first]+a1.second+a2.second);
		cout<<s+A[x]+A[y]<<"\n";
	}
 return 0;
}
