#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ans,w[500005],u,k[505],a,t,v,dis[500005+505],vis[500005+505];
struct byd{
	int v,w;
};
vector<byd>e[500605];
priority_queue<pair<long long,long long> >que;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			e[a].push_back({m+i,t});
			e[m+i].push_back({a,t});
		}
	}
	while(q--){
		cin>>u>>v;
		que.push({0,u});
		memset(dis,127,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dis[u]=0;
		while(!que.empty()){
			long long x=que.top().second;
			que.pop();
			if(vis[x]==1)continue;
			vis[x]=1;
			//cout<<x<<" start\n";
			for(int i=0;i<e[x].size();i++){
				long long y=e[x][i].w,z=e[x][i].v;
				if(dis[x]+y<dis[z]){
					dis[z]=dis[x]+y;
					que.push({-dis[z],z});
					//cout<<"push "<<dis[z]<<' '<<(z>m?"s":"")<<(z>m?z-m:z)<<'\n';
				}
			}
		}
		//for(int i=1;i<=m;i++)cout<<dis[i]<<' ';cout<<'\n';
		//for(int i=m+1;i<=m+n;i++)cout<<dis[i]<<' ';cout<<'\n';
		e[u].push_back({v,dis[v]});
		cout<<w[u]+w[v]+dis[v]<<'\n';
	}
	return 0;
}