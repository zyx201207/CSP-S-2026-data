#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000001],p;
long long dist[5001],ans[5001],vis[5001];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >q;
vector<int>edge[5001];
void dijkstra(int st){
	memset(dist,0x3f3f3f3f,sizeof(dist));
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
	q.push({0,st});
	dist[st]=0;
	ans[st]=1;
	while(!q.empty()){
		long long u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<edge[u].size();i++){
			if(dist[u]+1<dist[edge[u][i]]){
				dist[edge[u][i]]=dist[u]+1;
				q.push({dist[edge[u][i]],edge[u][i]});
				ans[edge[u][i]]=ans[u];
			}
			else if(dist[u]+1==dist[edge[u][i]])ans[edge[u][i]]+=ans[u];
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		p=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			if(d/(x[2]-x[1])<=1){cout<<0<<'\n';continue;}
			cout<<max(0ll,n-(d/(x[2]-x[1])*2-1))<<'\n';
			continue;
		}
		if(c<=10){
			for(int i=1;i<=n;i++)edge[i].clear();
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){
					if(abs(x[i]-x[j])<=d){
						edge[i].push_back(j);
						edge[j].push_back(i);
					}
				}
			}
			for(int i=1;i<=n;i++){
				dijkstra(i);
				for(int j=i+1;j<=n;j++){
					if(ans[j]==2)p++;
				}
			}
			cout<<p<<'\n';
			continue;
		}
	}
	return 0;
}