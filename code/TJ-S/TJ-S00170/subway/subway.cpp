#include<bits/stdc++.h>
using namespace std;
long long n,m,d,a[500005],b[500005][25],w[500005][25],sz[500005],dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long testid,q;
	cin>>testid>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long x,y;
			cin>>x>>y;
			b[x][++sz[x]]=i;
			w[x][sz[x]]=y;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			if(i!=j) dis[i][j]=1e18;
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=sz[i];j++){
			for(long long k=1;k<=sz[i];k++){
				dis[b[i][j]][b[i][k]]=min(dis[b[i][j]][b[i][k]],w[i][j]+w[i][k]);
			}
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(long long i=1;i<=sz[x];i++){
			for(long long j=1;j<=sz[y];j++){
				ans=min(ans,dis[b[x][i]][b[y][j]]+w[x][i]+w[y][j]);
			}
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
	return 0;
}
