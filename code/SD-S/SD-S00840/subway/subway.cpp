#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;
//using namespace __gnu_pbds;

const int N=505;
const int M=5e5+5;
const int inf=2e18;
int c,n,m,d,q;
int w[M],dis[N+M],vis[N+M],ans[M],E[N][N];
vector<pii> G[N+M];


void dijk(int s){
	priority_queue<pii,vector<pii>,greater<pii>>q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int x=q.top().se;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto tmp:G[x]){
			int y=tmp.fi,z=tmp.se;
			if(dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
				q.push({dis[y],y});
			}
		}
	}
}
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)E[i][j]=inf;
	for(int i=1;i<=n;i++){
		E[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			G[a].push_back({M+i,t});
			G[M+i].push_back({a,t});
		}
	} 
	for(int i=1;i<=m;i++){
//		int cnt=0;
		for(auto xmp:G[i]){
			for(auto ymp:G[i]){
				if(xmp==ymp)continue;
				int x=xmp.fi-M,y=ymp.fi-M,z=xmp.se+ymp.se;
//				E[x].push_back({y,z});
				E[x][y]=min(E[x][y],z);
//				cnt++;
			}
		}
//		cerr<<cnt<<"\n";
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i)continue;
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				E[i][j]=min(E[i][j],E[i][k]+E[k][j]);
			}
		}
	} 
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;int ans=inf;
		for(int j=0;j<G[x].size();j++){
			int xx=G[x][j].fi-M,z=G[x][j].se;
			for(int k=0;k<G[y].size();k++){
				int yy=G[y][k].fi-M,zz=G[y][k].se;
//				cout<<xx<<" "<<yy<<" "<<z<<" "<<zz<<" "<<E[xx][yy]<<"\n";
				ans=min(ans,E[xx][yy]+z+zz);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
signed main(){
//	freopen("subway7.in","r",stdin);
//	freopen("subway7.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}



