#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,T;
int n,d;
int a[2000010];
vector <int> e[2000010];
int dis[2000010];
int sum[2000010];
bool vis[2000010];
void dij(int S){
	for(int i=1;i<=n;i++)
		sum[i]=vis[i]=0,dis[i]=-1;
	priority_queue <pair<int,int> > q;
	q.push({0,S}),dis[S]=0,sum[S]=1;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])	continue;
		vis[u]=true;
		for(int v:e[u])
			if(dis[v]==-1||dis[v]>dis[u]+1)
				dis[v]=dis[u]+1,sum[v]=sum[u],q.push({-dis[v],v});
			else if(dis[v]==dis[u]+1)
				sum[v]+=sum[u];
	}
//	for(int i=1;i<=n;i++)
//		cout<<sum[i]<<' ';
//	cout<<"\n";
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i],e[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d)
					e[i].push_back(j); 
		int ans=0;
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=i+1;j<=n;j++)
				if(sum[j]==2)
					ans++;
		}
		cout<<ans<<"\n";			
	}
	return 0;
}//Baixie 0513DTY
//24pts.
