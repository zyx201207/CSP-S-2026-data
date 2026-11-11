#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5,M=505;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long C,n,m,k,s,w,x,y,T,a[N],u[N],d[N][M],dp[N][M];
struct node{
	long long f,id;
};
vector<node>g[N];
queue<node>q;
void bfs(int x,int y){
	memset(dp,inf,sizeof dp);
	q.push({x,0}); dp[x][0]=0;
	while(q.size()){
		node t=q.front(); q.pop();
		for(int i=0;i<g[t.f].size();i++){
			if(g[t.f][i].f==t.f&&g[t.f][i].id!=t.id){
				if(dp[t.f][t.id]+d[g[t.f][i].id][t.f]+d[t.id][t.f]<dp[t.f][g[t.f][i].id]){
					dp[t.f][g[t.f][i].id]=dp[t.f][t.id]+d[g[t.f][i].id][t.f]+d[t.id][t.f];
					q.push({t.f,g[t.f][i].id});
				}
			}
			else if(g[t.f][i].f!=t.f&&g[t.f][i].id==t.id){
				if(dp[t.f][t.id]<dp[g[t.f][i].f][t.id]){
					dp[g[t.f][i].f][t.id]=dp[t.f][t.id];
					q.push({g[t.f][i].f,t.id});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>k>>T;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=1;j<=s;j++){
			cin>>u[j]>>w;
			d[i][u[j]]=w;
			g[u[j]].push_back({u[j],i});
			if(j==1) continue;
			g[u[j-1]].push_back({u[j],i});
			g[u[j]].push_back({u[j-1],i});
			
		}
	}
	while(T--){
		cin>>x>>y;
		bfs(x,y);
		long long ans=inf;
		for(int i=0;i<=n;i++){
			ans=min(ans,dp[y][i]+d[i][y]);
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
	return 0;
}