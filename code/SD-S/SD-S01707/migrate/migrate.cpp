#include <bits/stdc++.h>
#define ll long long
#define mem(a , b) memset(a , b , sizeof a)
using namespace std;
const int N = 2e6+10;
ll n , d;
ll a[N];

ll tot = 0, head[N];
struct Node {
	ll next , to , w;
} edge[N];
void init() {
	tot = 1;
	mem(head , -1);
}
void add(ll x , ll y) {
	edge[tot].next = head[x];
	edge[tot].to = y;
	head[x] = tot++;
}
struct HoLuc {
	ll u , d;
};
ll ans = 0;
ll cnt[N];
ll dis[N];
bitset<N> vis;
void BFS(ll x) {
	queue<HoLuc> q;
	q.push({x , 0});
	vis.reset();
//	cout << "x:" << x << '\n';
	while(!q.empty()) {
		auto t = q.front();
		ll u = t.u;
		ll d = t.d;
		q.pop();
//		cout << "u:" << u << '\n';
		for(int i = head[u] ; ~i ; i = edge[i].next) {
			ll v = edge[i].to;
//			cout << v << ' ' << d  << ' ' << dis[v] << '\n';
			if(dis[v] == d + 1|| !dis[v]) {
//				cout << "238182";
				cnt[v]++;
				dis[v] = d + 1;
			}
			else continue;
			if(!vis[v]) {
				q.push({v , d + 1});
				vis[v] = 1;
			}
		}
	}
//	cout << "=============\n";
	for(int i = 1 ; i <= n ; i++) {
//		cout << cnt[i] << ' ';
		ans += (ll)(cnt[i] == 2);
		dis[i] = 0;
		cnt[i] = 0;
	}
//	cout << "\n=============\n";
}

vector<ll> b;
void solve() {
	// 多测清空
	ans = 0;
	init();
	cin >> n >> d;
	b.clear();
	b.resize(n + 1);
	for(int i = 1 ; i <= n ; i++) {
//		cin >> a[i];
//		b[i - 1] = a[i];
		cin >> b[i - 1];
	}
//	for(int i = 1 ; i <= n ; i++) {
//		a[i] = lower_bound(b.begin() , b.end() , a[i]) - b.begin() + 1;
////		cout << '-' << a[i] << ' ';
//	}
	b[n] = (ll)1e18;
//		cout << "--------------\n";
	for(int i = 1 ; i <= n ; i++) {
//		cout << b[i-1] << ' ';
		ll x = upper_bound(b.begin() , b.end() , b[i - 1] + d) - b.begin();// 能飞到的最远距离下标
		x = min(x , n);
//		cout << x << ' ';
		for(int j = i + 1 ; j <= x ; j++) {
//			cout << i << ' ' << j << '\n';
			add(i, j);
		}
	}
//		cout << "\n--------------\n";
	for(int i = 1 ; i <= n ; i++) {
//		cout << ans;
		BFS(i);
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 候鸟 全国可飞
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c , T;
	cin >> c >> T;
	while(T--) {
		solve();
	}
	return 0;
}
/*
Process exited after 0.1078 seconds with return value 0
请按任意键继续. . .

妈的，咋几把寄了 
妈的，不调了，有缘再会
赛后用 AI 调 

现在 17:46，migrate 的暴力已经写了一个半小时（从 AC T1->开始 T2）
现在 T2 的部分分拿到了，我又回来了 

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 3
-4 -3 -2 -1 3 6

0 1
6 4
1 2 5 6 8 9

*/
