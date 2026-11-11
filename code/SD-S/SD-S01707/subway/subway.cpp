#include <bits/stdc++.h>
#define mem(a , b) memset(a , b , sizeof a)
#define ll long long
#define inf 1000000000000000000
using namespace std;
const int M = 505;
const int N = 5e5+505;
ll n , m , d , q;
ll w[N];

ll tot = 0, head[N << 1];
struct Node {
	ll next , to , w;
} edge[N << 1];
void init() {
	tot = 1;
	mem(head , -1);
}
void add(ll x , ll y , ll w) {
	edge[tot].next = head[x];
	edge[tot].to = y;
	edge[tot].w = w;
	head[x] = tot++;
}
void add_(ll x , ll y , ll w) {
	add(x , y , w);
	add(y , x , w);
}

//vector<ll> a;
struct QUESTION{
	ll x , y;
	ll i; 
	bool operator < (const QUESTION&o) const {
		return x < o.x;
	}
}qwen[100005];
ll ans[100005];

struct HoLuc {
	ll u , d;
	bool operator < (const HoLuc&o) const {
		return d > o.d;
	}
};
priority_queue<HoLuc> claude;
vector<ll> dis;
bitset<N> vis;
void djistra(ll x) {
	dis.clear();
	vis.reset();
	dis.resize(n + m + 1);
	fill(dis.begin() , dis.end() , inf);
	claude.push({x, 0});
	dis[x] = 0;
	while(!claude.empty()) {
		ll u = claude.top().u;
//		cout << claude.top().d << ' ';
		claude.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		// 小克吹泡泡 claude.pop
//		cout << "u:" << u << '\n';
		 for(int i = head[u] ; ~i ; i = edge[i].next) {
		 	ll v = edge[i].to;
		 	ll w = edge[i].w;
//		 	cout << v << ',' << w << ' ';
		 	if(dis[v] > dis[u] + w) {
		 		dis[v] = dis[u] + w;
		 		if(!vis[v]) {
		 			claude.push({v , dis[v]});
				 }
			 }
		 }
//		 cout << '\n'; 
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	/*
	我了个 subway，熨斗学院的题 T1 叫能量水晶，T2 叫地铁，真对上了？严查！
	看到 d <= 20，没好的记忆涌上心头，T2 凸轮+美剧 
	*/
	int c;
	cin >> c;
	cin >> n >> m >> d >> q;
	init();
	for(int i = 1 ; i <= m ; i++) {
		cin >> w[i];
	}
	for(int i = 1 ; i <= n ; i++) {
		ll k;
		cin >> k;
		for(int j = 1 ; j <= k ; j++) {
			ll a , t;
			cin >> a >> t;
			add_(a , m + i , t);
		}
	}
	// 这时候你就发现，跑一遍全源最短路（Jeason）答案就出来了。 
	// 但是你不会全源最短路。 
	// 那咋办，那就跑单源呗。 
	// 把询问离线下来，然后跑单源。 
	// 虽然你发现你貌似没有用到 d，而且他一定有用，但是怕什么你又不是 AK CSP 来的。 
	// 但是，当你忘了 Djistra 咋写（wok，只记着英文咋拼了）时，你完全慌了。 
	// 这个 Dji 不知道写没写对，反正记忆里是这样的 
	// 按理说这个复杂度就是 O(q + (m + n) ^ 2 log (m + n) 的水平，样例 4 完全就是这个水平)
	// 那看来，还是 djistra 打错了啊......还是要巩固基础
	// 万一是这个电脑配置太烂呢...? 
	for(int i = 1 ; i <= q ; i++) {
		cin >> qwen[i].x >> qwen[i].y;
		qwen[i].i = i;
	} 
	sort(qwen + 1 , qwen + 1 + q);
	ll lst = 0;
	for(int i = 1 ; i <= q ; i++) {
		if(qwen[i].x ^ lst) {
			djistra(qwen[i].x);
		}
		ans[qwen[i].i] = w[qwen[i].x] + dis[qwen[i].y] + w[qwen[i].y];
	}
	for(int i = 1 ; i <= q ; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}
// 17:27，样例三过了，有点激动
// 但是 4 RE 了
// 妈的，不 RE 了， TLE 了 
// 但是过了
// 希望 CCF 少爷机给点力，卡进去 
// 其实我最喜欢的模型是 deepseek 和 GPT
// Grok 也很可爱
// claude 要是不封号的话就好了
 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
