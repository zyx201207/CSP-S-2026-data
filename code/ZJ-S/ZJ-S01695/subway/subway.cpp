#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=500010;
int w[N];
vector<pair<int,int> >g[N];
int dis[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int len;
		cin>>len;
		for(int j=1;j<=len;j++){
			int x,t;
			cin>>x>>t;
			g[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		int len=g[i].size();
		for(int j=0;j<len;j++){
			for(int k=j+1;k<len;k++){
				int x=g[i][j].first,y=g[i][k].first,z=g[i][j].second+g[i][k].second;
				dis[x][y]=min(dis[x][y],z);
				dis[y][x]=min(dis[y][x],z);
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
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto i:g[x]){
			for(auto j:g[y]){
				ans=min(ans,w[x]+w[y]+i.second+j.second+dis[i.first][j.first]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}