#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 2000005;
const int INF=0x3f3f3f3f;
ll a[N], f[N];
int dis[N];
bool vis[N];
vector<int> G[N];
struct Node{
	int v,w;
	bool operator<(const Node &rhs)const{
		return rhs.w<w;
	}
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==j) continue;
				if(llabs(a[i]-a[j])<=d){
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		ll ans = 0;
		for(int s=1;s<=n;s++){
			priority_queue<Node> q;
			for(int i=1;i<=n;i++) dis[i] = INF,vis[i]=0,f[i] = 0;
			f[s]=1;
			q.push({s,dis[s]=0});
			while(!q.empty()){
				int u=q.top().v;
				q.pop();
				if(vis[u]) continue;
				vis[u]=1;
				for(auto v:G[u]){
					if(dis[v] > dis[u] + 1){
						f[v] = f[u];
						q.push({v, dis[v] = dis[u] + 1});
					} else if(dis[v] == dis[u] + 1) f[v]++;
				}
			}
			for(int i=1;i<=n;i++) {
				if(f[i] == 2) ans++;
			}
		}
		ans/=2;
		cout<<ans<<"\n";
	}
	return 0;
}