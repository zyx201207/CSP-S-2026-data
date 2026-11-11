#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+10;
const ll INF=2e18+1;
int c,n,t;
ll x[maxn],d,dist[maxn],cnt[maxn];
void dijkstra(int s){
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		ll dis=q.top().first;
		q.pop();
		if(dis!=dist[u])continue;
		for(int i=u+1;i<=n;i++){
			int v=i;
			if(x[v]-x[u]<=d){
				if(dis+1==dist[v])cnt[v]++,q.push({dist[v],v});
				else if(dis+1<dist[v]){
					cnt[v]=1;
					dist[v]=dis+1;
					q.push({dist[v],v});
				}
			} 
//			else break;
		}
		
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dist[j]=INF,cnt[j]=0;
			dist[i]=0;
			dijkstra(i);
			for(int j=1;j<=n;j++){
			//	cout<<cnt[j]<<'\n'; 
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
