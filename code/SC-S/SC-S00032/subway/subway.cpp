#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
const int B=5e5+5;
const int T=1e7;
int a[B];
vector<pair<int,int> >g[T];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int s,t;
			cin>>s>>t;
			g[m+i].push_back({s,t});
			g[s].push_back({m+i,t});
		}
	}while(q--){
		int x,y;
		cin>>x>>y;
		priority_queue<pr,vector<pr>,greater<pr> >q1;
		vector<int>dist(n+m+1,1e18); 
		vector<int>vis(n+m+1,0); 
		q1.push({x,0});
		dist[x]=0;
		while(!q1.empty()){
			int u=q1.top().first,sum=q1.top().second;
			vis[u]=1;
			q1.pop();
			for(auto op:g[u]){
				int v=op.first,w=op.second;
				if(dist[v]>sum+w){
					dist[v]=sum+w;
				}if(vis[v]==0)q1.push({v,dist[v]});
			}
		}cout<<dist[y]+a[x]+a[y]<<endl;
	}
	return 0;
}  