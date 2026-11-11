#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define __low lower_bound
#define __upp upper_bound
#define pii pair<int,int>
#define MP make_pair
#define fi first
#define se second
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e5+5;
const ll INF = 1e18;

int c, n, m, d, Q;
int w[N];

struct pp{
	ll x, w;
	bool operator < (const pp &a) const{
		return w > a.w;
	}
};
vector<pp> ve[N];
priority_queue<pp> q;

int dp[N];
bool vis[N];

void init(){
	for(int i = 1; i <= n+m; i++){
		dp[i] = 1e9, vis[i] = 0;
	}
	while(q.size()) q.pop();
}

ll dij(int be, int to){
	init();
	q.push({be, 0});
	dp[be] = 0;
	while(q.size()){
		ll x = q.top().x, w = q.top().w;
		q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		if(x == to) return w;
		for(auto i : ve[x]){
			int y = i.x, ww = w + i.w;
			if(ww < dp[y]){
				dp[y] = ww;
				q.push({y, dp[y]});
			}
		}
	}
	return INF;
} 

int main(){
	freopen("subway.in", "r", stdin);
	freopen("baoli.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k, x, w;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> x >> w;
			ve[x+n].pb({i, w});
			ve[i].pb({x+n, w});
		}
	}
	
	while(Q--){
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] + dij(x+n, y+n) << "\n";
	}
	
	return 0;
} 
