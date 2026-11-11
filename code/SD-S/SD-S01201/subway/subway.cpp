#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=505,M=5e5+5,inf=1e18;
int c,n,m,d,q,w[M],k[N],dis[N][N];
vector<pair<int,int> > v[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		int siz=v[i].size();
		for(int j=0;j<siz;j++){
			for(int k=0;k<siz;k++){
				if(j==k) continue;
				dis[v[i][j].first][v[i][k].first]=min(dis[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
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
	for(int i=1;i<=q;i++){
		int x,y,ans=inf;
		cin>>x>>y;
		int siza=v[x].size(),sizb=v[y].size();
		for(int j=0;j<siza;j++){
			for(int k=0;k<sizb;k++){
				ans=min(ans,w[x]+w[y]+v[x][j].second+v[y][k].second+dis[v[x][j].first][v[y][k].first]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

