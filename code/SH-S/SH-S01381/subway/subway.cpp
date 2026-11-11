#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+5,N=505;
int c,n,m,d,q,cnt[M];
ll w[M],dis[N][N],ans;
pair<int,ll>a[M][25];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,t1,t2;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>t1>>t2;
			a[t1][++cnt[t1]]={i,t2};
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				dis[a[i][j].first][a[i][k].first]=min(dis[a[i][j].first][a[i][k].first],a[i][j].second+a[i][k].second);
				dis[a[i][k].first][a[i][j].first]=min(dis[a[i][k].first][a[i][j].first],a[i][j].second+a[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}cout<<endl;
//	}
	while(q--){
		int x,y;
		ans=LONG_LONG_MAX;
		cin>>x>>y;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				ans=min(ans,a[x][i].second+a[y][j].second+dis[a[x][i].first][a[y][j].first]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
