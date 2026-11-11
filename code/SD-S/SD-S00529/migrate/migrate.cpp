#include<bits/stdc++.h>
#define int long long
#define INF 4e18
#define PII pair<int,int>
using namespace std;
const int N=5005;
int c,t,dist[N],vis[N],cnt[N],n,d,x[N];
struct node{
	int v,w;
};
vector<node> a[N]; 
void add(int u,int v,int w){
	a[u].push_back({v,w});
}
void dijkstra(int s){
	for(int i=1;i<=n;i++){
		dist[i]=INF;
		vis[i]=0;
		cnt[i]=0;
	}
	cnt[s]=1;
	dist[s]=0;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(auto it:a[u]){
			int v=it.v,w=it.w;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				cnt[v]=cnt[u];
				q.push({dist[v],v});
			}else if(dist[v]==dist[u]+w){
				cnt[v]+=cnt[u];
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			a[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					add(i,j,1);
					add(j,i,1);
				//	cout<<i<<" "<<j<<"\n";
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}

