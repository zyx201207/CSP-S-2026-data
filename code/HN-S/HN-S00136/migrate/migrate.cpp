#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pi pair<int,int>
#define mini pi,vector<pi>,greater<pi>
#define fs first
#define se second
#define P_Q priority_queue
using namespace std;
const int N = 2e6 + 5, inf = 0x3f3f3f3f3f3f3f3f;

int n, d;
int a[N];
vector<pi> v[N];
int ans = 0;

int dis[N];
int vis[N];
void bfs(int st){
	P_Q<mini> q;
	for(int i = 1;i <= n;i++) dis[i] = inf;//, vis[i] = 0;
	q.push({0, st});
	dis[st] = 0;
//	vis[st] = 1;
	while(q.size()){
		auto tp = q.top();q.pop();
		int x = tp.se;
		for(auto f : v[x]){
			int y = f.fs, w = f.se;
//			if(vis[y] > n) continue;
//			vis[y] = 1;
			if(dis[n] == dis[y]) ans++;
			dis[y] = min(dis[y], dis[x] + w);
			q.push({dis[y], y});
		}
	}
}

void solve(){
	ans = 0;
	cin >> n >> d;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		v[i - 1].push_back({i, a[i] - a[i - 1]});
	}
	
	bfs(1);
	cout << ans << endl;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin); freopen("migrate.out","w",stdout);

	int c, t;
	cin >> c >> t;
	while(t--) solve();

	return 0;
}

