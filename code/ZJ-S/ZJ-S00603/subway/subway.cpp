#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2005,M=1e18,K=2e4+505;
int c,m,n,d,r,k,x,y,dis[N][N],p[K],dp[K];
vector<pair<int,int> > v[K];
priority_queue<pair<int,int>,vector<pair<int,int> >
,greater<pair<int,int> > > q;
void dij(int x){
	for(int i=1;i<=n+m;i++) dis[x][i]=M;
	dis[x][x]=0;
	q.push({0,x});
	while(!q.empty()){
		int d=q.top().first,u=q.top().second;
		q.pop();
		if(dis[x][u]!=d) continue;
		for(auto i:v[u]){
			int fi=i.first,se=i.second;
			if(d+se<dis[x][fi]){
				dis[x][fi]=d+se;
				q.push({dis[x][fi],fi});
			}
		}
	}
}
void dij1(int x){
	for(int i=1;i<=n+m;i++) dp[i]=M;
	dp[x]=0;
	q.push({0,x});
	while(!q.empty()){
		int d=q.top().first,u=q.top().second;
		q.pop();
		if(dp[u]!=d) continue;
		for(auto i:v[u]){
			int fi=i.first,se=i.second;
			if(d+se<dp[fi]){
				dp[fi]=d+se;
				q.push({dp[fi],fi});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;++i) cin>>p[i];
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>x>>y;
			v[x].push_back({i+m,y});
			v[i+m].push_back({x,y});
		}
	}
	if(c>=12 && c<=15){
		for(int i=1;i<=r;i++){
			cin>>x>>y;
			dij1(x);
			cout<<dp[y]+p[x]+p[y]<<"\n";
		}
		return 0;	
	}
	for(int i=1;i<=m;i++) dij(i);
	for(int i=1;i<=r;i++){
		cin>>x>>y;
		cout<<dis[x][y]+p[x]+p[y]<<"\n";
	}
	return 0;
}

