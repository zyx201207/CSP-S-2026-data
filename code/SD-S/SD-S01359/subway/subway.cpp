#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],sw[505][505];
vector<long long> a[505],t[505];
vector<long long> b[500005],u[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=n;i++){
		a[i].push_back(0);
		t[i].push_back(0);
	}
	for(long long i=1;i<=m;i++){
		b[i].push_back(0);
		u[i].push_back(0);
	}
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			long long la,lt;
			cin>>la>>lt;
			a[i].push_back(la);
			t[i].push_back(lt);
			b[la].push_back(i);
			u[la].push_back(lt);
		}
	}
	for(long long i=1;i<=n;i++)for(long long j=1;j<=n;j++)sw[i][j]=(long long)(1ll<<61);
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=k[i];j++)
			for(long long l=1;l<b[j].size();l++)
				if(t[i][j]+u[ a[i][j] ][l]<sw[i][ b[a[i][j]][l] ])sw[i][ b[a[i][j]][l] ]=t[i][j]+u[ a[i][j] ][l];
	for(long long l=1;l<=n;l++)
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=n;j++)
				if(sw[i][l]+sw[l][j]<sw[i][j])sw[i][j]=sw[i][l]+sw[l][j];
	for(long long r=1;r<=q;r++){
		long long x,y,ans=(long long)(1ll<<62);
		cin>>x>>y;
		for(long long i=1;i<b[x].size();i++)
			for(long long j=1;j<b[y].size();j++)
				if(u[x][i]+sw[b[x][i]][b[y][j]]+u[y][j]<ans)ans=u[x][i]+sw[b[x][i]][b[y][j]]+u[y][j];
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
/*
图灵保佑我多得几分 orz 
*/
