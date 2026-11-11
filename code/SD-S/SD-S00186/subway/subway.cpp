#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5,D=23;
int c,n,m,d,q,w[M],cnt[M];
ll f[N][N],ans;
pair<int,int> e[M][D];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			e[x][++cnt[x]]=make_pair(i,y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=4e18;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				int u=e[i][j].first,v=e[i][k].first;
				f[u][v]=f[v][u]=min(f[u][v],1ll*e[i][j].second+e[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		ans=4e18;
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				ans=min(ans,f[e[x][i].first][e[y][j].first]+e[x][i].second+e[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
