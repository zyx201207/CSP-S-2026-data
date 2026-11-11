#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,inf=1e18;
int c,n,m,d,q,w[M],dis[N][N];
struct node{
	int id,t;
};
vector<node>v[M];
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			v[a].push_back({i,t}); 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<v[i].size();k++){
				int x=v[i][j].id,y=v[i][k].id;
				dis[x][y]=min(dis[x][y],v[i][j].t+v[i][k].t);
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
		for(int j=0;j<v[x].size();j++){
			for(int k=0;k<v[y].size();k++){
				ans=min(ans,w[x]+w[y]+v[x][j].t+v[y][k].t+dis[v[x][j].id][v[y][k].id]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}