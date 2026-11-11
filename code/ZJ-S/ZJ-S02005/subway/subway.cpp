#include<bits/stdc++.h>
#define int long long
#define pi pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=500+5,M=5e5+5,inf=1e17;
int dis[N][N],f[N][N],w[M];
vector<pi> sta[M],v[N];
bool vis[N];
signed main(){
	freopen("subway.in","r",stdin);//WAR
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,n,m,d,Q;
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int j=1;j<=t;j++){
			int x,y;
			cin>>x>>y;
			sta[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				dis[i][j]=inf;
			}
			else{
				dis[i][j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<sta[i].size();j++){
			for(int k=j+1;k<sta[i].size();k++){
				pi x=sta[i][j],y=sta[i][k];
				dis[x.fi][y.fi]=min(dis[x.fi][y.fi],x.se+y.se);
				dis[y.fi][x.fi]=min(dis[y.fi][x.fi],x.se+y.se);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&dis[i][j]!=inf){
				v[i].push_back({j,dis[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=inf;
			vis[j]=0;
		}
		f[i][i]=0;
		priority_queue<pi> p;
		p.push({0,i});
		while(!p.empty()){
			int x=-p.top().fi,y=p.top().se;
			p.pop();
			if(vis[y]){
				continue;
			}
			vis[y]=1;
			for(pi j:v[y]){
				if(vis[j.fi]){
					continue;
				}
				if(x+j.se<f[i][j.fi]){
					f[i][j.fi]=x+j.se;
					p.push({-x-j.se,j.fi});
				}
			}
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		int minn=inf;
		for(pi i:sta[x]){
			for(pi j:sta[y]){
				minn=min(minn,f[i.fi][j.fi]+i.se+j.se);
			}
		}
		cout<<minn+w[x]+w[y]<<"\n";
	}
	return 0;
}