#include<bits/stdc++.h>
using namespace std;
//#define int long long
int tid,n,m,deg,q;
int w[500005];
int siz[500005];
long long dis[505][505];
pair<int,int> a[500005][22];
void sol(long long& x,long long y){
	x=min(x,y);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> tid >> n >> m >> deg >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=n;i++){
		int len;cin >> len;
		while(len--){
			int x,t;
			cin >> x >> t;
			siz[x]++;
			a[x][siz[x]]={i,t};
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1LL<<57;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<siz[i];j++){
			for(int k=j+1;k<=siz[i];k++){
				sol(dis[a[i][j].first][a[i][k].first],a[i][j].second+a[i][k].second);
				sol(dis[a[i][k].first][a[i][j].first],a[i][j].second+a[i][k].second);
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				sol(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	
	
	while(q--){
		int x,y;cin >> x >> y;
		long long ans=1LL<<61;
		for(int i=1;i<=siz[x];i++){
			for(int j=1;j<=siz[y];j++){
				ans=min(ans,a[x][i].second+a[y][j].second+dis[a[x][i].first][a[y][j].first]);
			}
		}
		ans+=w[x]+w[y];
		cout << ans << "\n";
	}
	return 0;
}
