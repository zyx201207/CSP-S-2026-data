#include <bits/stdc++.h>
using namespace std;

const int N=2e6+5;
long long c,t,n,d,x[N],dis[N],cnt[N],vis[N];
vector<int> e[N];
struct node{
	int id;
	long long val;
	bool operator<(const node &o)const{
		return val>o.val;
	}
};

void dijkstra(int s){
	priority_queue<node> q;
	fill(dis+1,dis+n+1,1e18);
	fill(vis+1,vis+n+1,0);
	fill(cnt+1,cnt+n+1,1);
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		long long u=q.top().id,val=q.top().val;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push({v,dis[v]});
			}else if(dis[v]==dis[u]+1){
				cnt[v]++;
			}
		}
	}
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i],e[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&abs(x[i]-x[j])<=d){
				e[i].push_back(j),e[j].push_back(i);
//				cout<<i<<' '<<j<<'\n';
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=1;j<=n;j++)ans+=(cnt[j]==4);
	}
	cout<<(ans/2)<<'\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>t;
	for(;t--;)solve();
	return 0;
}

