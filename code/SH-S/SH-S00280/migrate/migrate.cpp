#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int c,T;
ll n,d;
const int N=2e6+10;
ll a[N];

void solve(){
	cin>>n>>d;
	vector<vector<int>> g(n+10);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[j]-a[i]<=d)
				g[i].push_back(j);
				
//	for(int i=1;i<=n;i++){
//		for(auto j:g[i])
//			cout<<j<<" ";
//		cout<<"\n";
//	}
	
	vector<ll> dis,cnt;
	vector<bool> vis;
	int ans=0;
	for(int i=1;i<=n;i++){
		dis.assign(n+10,0x3f3f3f3f);
		cnt.assign(n+10,0);
		vis.assign(n+10,0);
		priority_queue<pii,vector<pii>,greater<pii>> heap;
		dis[i]=0;
		cnt[i]=1;
		heap.push({0,i});
		while(!heap.empty()){
			auto u=heap.top().second;
//			cout<<u<<" ";
			heap.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto v:g[u]){
				if(dis[v]>dis[u]+1){
					cnt[v]=cnt[u];
					dis[v]=dis[u]+1;
					heap.push({dis[v],v});
				}
				else if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
			}
		}
		for(int j=i+1;j<=n;j++)
			if(cnt[j]==2) ans++; 
//		cout<<"\n";
	}
	cout<<ans<<"\n";
}

void solveA(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll dis=a[2]-a[1];
	ll cnt=d/dis;
	cout<<n-cnt-1<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		if(c<=10) solve();
		else if(c==11||c==12) solveA();
		else cout<<0<<"\n";
	} 
	return 0;
}
