#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[5005];
vector<int>g[5005];
struct node{
	int u,d;
	friend bool operator < (const node &a,const node &b){
		return a.d<b.d;
	}
};
struct d{
	int v,cnt;
}dist[5005];
queue<node>q;
void dijkstra(int u){
	q.push({u,0});
	for(int i=u+1;i<=n;i++){
		dist[i]={0x3f3f3f3f,0};
	}
	dist[u]={0,0};
	while(!q.empty()){
		u=q.front().u;
		q.pop();
		for(int v:g[u]){
			if(dist[u].v+1<=dist[v].v){
				if(dist[u].v+1==dist[v].v){
					dist[v]={dist[u].v+1,dist[u].cnt+1};
					if(dist[u].cnt>2){
						return;
					}
				}
				else{
					dist[v]={dist[u].v+1,1};
				}
				q.push({v,dist[v].v});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					g[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=i+1;j<=n;j++){
				if(dist[j].cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}