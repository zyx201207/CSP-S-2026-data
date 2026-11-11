#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
namespace Rain_Cloud{
	const int M=5e5+7,N=507;
	int c,n,m,d,q;
	int cnt[M];
	int haoma[M][25];
	long long t[M][25];
	long long w[M];
	long long dist[N][N];
	void RainS(){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int hao;
				long long shi;
				cin>>hao>>shi;
				haoma[hao][++cnt[hao]]=i;
				t[hao][cnt[hao]]=shi;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++) dist[i][i]=0;
		for(int now=1;now<=m;now++){
			for(int i=1;i<=cnt[now];i++){
				int u=haoma[now][i];
				long long shi1=t[now][i];
				for(int j=i+1;j<=cnt[now];j++){
					int v=haoma[now][j];
					long long shi2=t[now][j];
					dist[u][v]=min(dist[u][v],shi1+shi2);
					dist[v][u]=min(dist[v][u],shi1+shi2);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			long long ans=1e18;
			for(int i=1;i<=cnt[x];i++){
				int u=haoma[x][i];
				for(int j=1;j<=cnt[y];j++){
					int v=haoma[y][j];
					ans=min(ans,t[x][i]+t[y][j]+dist[u][v]);
				}
			}
			cout<<ans+w[x]+w[y]<<'\n';
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Rain_Cloud::RainS();
	return 0;
}
