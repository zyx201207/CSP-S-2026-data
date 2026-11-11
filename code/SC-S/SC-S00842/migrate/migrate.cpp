#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
vector<int> g[N];
int a[N];
bool DIJ(int x,int y){
	vector<int> dis(N,1e18);
	vector<bool> vis(N,0);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	dis[x]=0;
	q.push({0,x});
	int sum=1e18,t=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])	continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(v==y){
				if(dis[u]+1<sum){
					sum=dis[u]+1;
					t=1;
				}
				else if(dis[u]+1==sum)	t++;
				
			}
			else if(v<y){
				if(dis[u]+1<dis[v]){
					dis[v]=dis[u]+1;
					q.push({dis[v],v});
				}
			}
		}
	}
	if(t==2)	return 1;
	else	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];	
			g[i].clear();
		}
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[j]-a[i]<=d)	g[i].push_back(j);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(DIJ(i,j))	ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
