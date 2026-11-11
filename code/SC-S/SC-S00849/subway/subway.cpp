#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long w[N];
struct qp{
	long long v,w;
};
vector<qp> g[N]; 
long long floyd[410][410];
long long ans[1510][1510];
long long sc1[N],sc2[N];
long long c,n,m,d,fc;
struct dist{
	long long u,w;
};
bool operator < (const dist& a,const dist& b){
	return a.w <b.w;
}
priority_queue<dist> q; 
bool vis[N],_1[N],_2[N];
void dijkstra(int s){
	for(int i=1;i<=m+n;i++) vis[i]=0,ans[s][i]=1e18;
	ans[s][s]=0;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto c:g[u]){
			int v=c.v,w=c.w;
			if(ans[s][u]+w<ans[s][v]){
				ans[s][v]=ans[s][u]+w;
				vis[v]=0;
				q.push({v,ans[s][v]});
			}
		}
	}
}
int main()
{
	freopen("subway","r",stdin);
	freopen("subway","w",stdout);
	cin>>c>>n>>m>>d>>fc; 
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c<=6){
		for(long long i=1;i<=m+n;i++){
			for(long long j=1;j<=m+n;j++)floyd[i][j]=1e18;
		}
	}
	if(c<=21&&c>=20){//贪心 c<=21 8pts 
		long long num,x,t,minn=1e18;
		cin>>num;
		for(long long j=1;j<=num;j++){
			cin>>x>>t;
			_1[x]=1,sc1[x]=t;
		}
		cin>>num;
		for(long long j=1;j<=num;j++){
			cin>>x>>t;
			_2[x]=1,sc2[x]=t;
			if(_1[x]) minn=min(minn,sc1[x]+sc2[x]);
		}
		long long s;
		while(fc--){
			cin>>s>>t;
			if(_1[s]&&_1[t]) cout<<w[s]+w[t]<<endl;
			else if(_2[s]&&_2[t]) cout<<w[s]+w[t]<<endl;
			else cout<<w[s]+w[t]+minn<<endl;
		}
		return 0;
	}
	for(long long i=1;i<=n;i++){
		long long num,x,t;
		cin>>num;
		for(long long j=1;j<=num;j++){
			cin>>x>>t;
			g[i+m].push_back({x,t});
			g[x].push_back({i+m,t});
			if(c<=6) floyd[i+m][x]=t,floyd[x][i+m]=t;
		}
	}
	if(c<=6){//Floyd c<=6 24pts 
		for(long long k=1;k<=m+n;k++){
			for(long long i=1;i<=m+n;i++){
				for(long long j=1;j<=m+n;j++){
					floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]); 
				}
			}
		}
		long long s,t;
		while(fc--){
			cin>>s>>t;
			cout<<w[s]+w[t]+floyd[s][t]<<endl;
		} 
		return 0;
	}
	if(c<=19){//dijkstra c<=19 52pts
		for(long long s=1;s<=m;s++){
			dijkstra(s);
		}
		long long s,t;
		while(fc--){
			cin>>s>>t;
			cout<<w[s]+w[t]+ans[s][t]<<endl;
		} 
		return 0;
	}
	return 0;
}
//算法?
//石山石山石山 
//过程十分崩溃 
//啊啊啊啊啊啊啊啊啊啊啊 
//84 pts 1:50:39