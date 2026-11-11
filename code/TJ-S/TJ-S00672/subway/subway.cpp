#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;

inline void cmin(ll &x, ll y) 
{
	if(x > y) x = y;
}

constexpr ll N = 5e2+10, M = 5e5+5, D = 30, inf = 1e17;

ll testid, n, m, d, q, w[M], dis[N][N];
vector<pa> vec[M];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	
	// 输入信息
	// 让每个 vec[x] 表示站台 x 拥有的 (线路,消耗) 
	cin >> testid >> n >> m >> d >> q;
//	printf("%lld %lld m=%lld %lld %lld\n", testid, n, m, d, q);
	for(ll i = 1; i <= m; i++) {
		cin >> w[i];
//		printf("%lld ", w[i]);
	} 
//	printf("\n");
	for(ll i = 1; i <= n; i++) {
		ll k = 0, x = 0, t = 0; cin >> k;
//		printf("%lld ", k);
		for(ll j = 1; j <= k; j++) {
			cin >> x >> t;
//			printf("%lld %lld ", x, t);
//			if(x == 1) {
//				printf("(%lld %lld)\n", i, t);
//			}
			vec[x].emplace_back(i,t);
		}
//		printf("\n");
	}
	
	//
//	printf("vec:\n");
//	for(ll i = 1; i <= 400; i++) {
//		printf("at %lld:", i);
//		for(auto ele : vec[i]) {
//			printf("(%lld %lld)", ele.first,ele.second);
//		}
//		printf("\n");
//	}
//	printf("\n");
	//
	
	// 预处理长度
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j < i; j++) {
			dis[i][j] = dis[j][i] = inf; 
		}
	} 
	// 对于每组把长度更新上去 
	for(ll i = 1; i <= m; i++) {
//		printf("at %d:\n", m);
		for(auto ele1 : vec[i]) {
			ll u = ele1.first, w1 = ele1.second;
			for(auto ele2 : vec[i]) {
				ll v = ele2.first, w2 = ele2.second;
				if(u == v) continue;
//				printf("update %lld to (%d,%d)%lld\n", w1+w2, u,v,dis[u][v]);
				cmin(dis[u][v], w1+w2);
				cmin(dis[v][u], w1+w2);
			}
		}
	}
	// debug
//	printf("dis:\n");
//	for(ll i = 1; i <= n; i++) {
//		for(ll j = 1; j <= n; j++) {
//			printf("%lld ", dis[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	//
	// 跑一轮floyd 
	for(ll k = 1; k <= n; k++) {
		for(ll i = 1; i <= n; i++) {
			for(ll j = 1; j <= n; j++) {
				cmin(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	// 此时满足 dis 就是两个站台的结果了  
	// 由于一定联通 我们这里不额外对超过上限的结果做书写  
	// 大概分析一下, n个站台每个站台2e9最多也就是1e12 
	
	// debug
//	printf("dis:\n");
//	for(ll i = 1; i <= n; i++) {
//		for(ll j = 1; j <= n; j++) {
//			printf("%lld ", dis[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
	//
	
	// 回答询问 
	for(ll round = 0, x = 0, y = 0; round < q; round++) {
		cin >> x >> y;
		ll ans = inf; 
		for(auto ue : vec[x]) {
			ll u = ue.first, c1 = ue.second;
			for(auto ve : vec[y]) {
				ll v = ve.first, c2 = ve.second;
				cmin(ans, c1+c2+dis[u][v]);
			}
		}
		cout << w[x]+w[y]+ans << "\n";
	}
	
	return 0;
}
