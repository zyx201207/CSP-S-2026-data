#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int M=5e5+7,N=507,inf=1e18+7;
int w[M];
int k[N];
int dis[N][N];
int c,n,m,d,q;
vector<PII>g[M];
vector<PII>G[N];

priority_queue<PII,vector<PII>,greater<PII> >qq;

void dj(int st){
	qq.push({0,st});
	
	while(!qq.empty()){
		PII q1=qq.top();qq.pop();
		int sum=q1.first,u=q1.second;
		if(dis[st][u]<sum)continue;
		for(PII q2:G[u]){
			int v=q2.first,t=q2.second;
			if(dis[st][v]<=sum+t)continue;
			dis[st][v]=sum+t;
			qq.push({sum+t,v});
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)cin>>w[i];
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int p1=0;p1<g[i].size();p1++){
			int u1=g[i][p1].first,t1=g[i][p1].second;
			for(int p2=0;p2<p1;p2++){
				int u2=g[i][p2].first,t2=g[i][p2].second;
				G[u1].push_back({u2,t1+t2});
				G[u2].push_back({u1,t1+t2});
//				cout<<u1<<" "<<u2<<" "<<t1+t2<<"\n";
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dis[i][j]=inf;
		dis[i][i]=0;
		dj(i);
//		for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";
//		cout<<"\n";
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int s=w[x]+w[y];
		int minn=inf;
		for(PII p1:g[x]){
			int v1=p1.first,t1=p1.second;
			for(PII p2:g[y]){
				int v2=p2.first,t2=p2.second;
				minn=min(minn,t1+t2+dis[v1][v2]);
//				cout
			}
		}
		cout<<minn+s<<"\n";
	}
	return 0;
}