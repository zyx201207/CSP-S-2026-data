#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
using namespace std;
const int N=2e6+10;
const ll inf=1e18;
ll a[N];
vector<pii>g[N];
ll n,d;
pii dis[N];
pii dij(int st,int ed){
	priority_queue<pii,vector<pii>,greater<pii>>pq;
	pq.push({0,st});
	for(int i=1;i<=n;i++){
		dis[i]={inf,0};
	}
	dis[st]={0,1};
	while(pq.size()){
		int u=pq.top().second;
		pq.pop();
		for(auto nxt:g[u]){
			int v=nxt.first;
			int we=nxt.second;
			if(dis[v].first<dis[u].first+we){
				continue;
			}else if(dis[v].first==dis[u].first+we){
				dis[v].second++;
			}else{
				dis[v].second=1;
				dis[v].first=dis[u].first+we;
			}
			pq.push({dis[v].first,v});
		}
	}
	return dis[ed];  
}
void solve(){
	cin>>n>>d;
	ll mid=0;
	for(ll i=1;i<=n;i++){
		g[i].clear();
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			mid=a[i]-a[i-1];
			if(mid<=d){
				g[i].push_back({i-1,mid});
				g[i-1].push_back({i,mid});
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&dij(i,j).first==2){
				cnt++;
			}
		}
	}
	cout<<cnt<<"\n";
}
void solve1(){
	cin>>n>>d;
	ll mid=0;
	for(ll i=1;i<=n;i++){
		g[i].clear();
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			mid=a[i]-a[i-1];
			if(mid<=d){
				g[i].push_back({i-1,mid});
				g[i-1].push_back({i,mid});
			}else{
				cout<<0<<"\n";
				return ;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c>=11&&c<=12){
		while(t--){
			solve1();
		}
	}else{
		while(t--){
			solve();
		}
	}
	
	return 0;
}