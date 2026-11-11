#include<bits/stdc++.h>
using namespace std;
long long ID,n,m,D,q,f[501][501],w[500001],K[501],sz[500001];
vector<long long>p[500001],t[500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>ID>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=m;i++)p[i].push_back(0),t[i].push_back(0);
	for(int i=1;i<=n;i++){
		cin>>K[i];
		for(int j=1;j<=K[i];j++){
			long long x,y;
			cin>>x>>y;
			sz[x]++;
			p[x].push_back(i),t[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=1145141919810000;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=sz[i];j++)for(int jj=1;jj<=sz[i];jj++){
			const long long k=p[i][j],kk=p[i][jj],tt=t[i][j]+t[i][jj];
			f[k][kk]=f[kk][k]=min(f[k][kk],tt);
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(;q;q--){
		int x,y;
		cin>>x>>y;
		long long ans=1145141919810000;
		for(int j=1;j<=sz[x];j++)for(int jj=1;jj<=sz[y];jj++){
			const int k=p[x][j],kk=p[y][jj];
			ans=min(ans,t[x][j]+t[y][jj]+f[k][kk]);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

