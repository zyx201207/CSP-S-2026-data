#include <bits/stdc++.h>
using namespace std;
#define fir(i, l, r) for(int i = (l); i <= (int) r; i++)
#define fpr(i, r, l) for(int i = (r); i >= (int) l; i--)
#define int long long
/*
考虑双路径的含义。
使用调整法。
对于 (u, v) 首先我们找到一个可行路径。
也就是前面先每次跳最远，最后一个跳到 v
设“活动点”的定义为，把这个移动到左边一个，还是可以。
我们设关键点就是active(x) && ! actvie(i - 1)
那么要求关键点只有一个！。
我们设出[l_i,r_i]
那么我们要求这些 [l,r] 相邻区间的交集大小 - 1的 sum 为 1！！！
那么这个怎么做。
设 dp[i][j(0/1)] 表示经过 i 的当前交集和为 j 的方案数。
我是小猫娘！

但是这样 j 可能比较多喵。
因此我们是不是要一个线段树喵。
感觉 1= 线至少 300 喵。
正在比较文件 subway.out 和 SUBWAY.ANS
FC: 找不到差异
反正 NOI LINUX 下面过了。
2e6 卡常喵。
树状数组不会喵。

顺便看下特殊性质喵。

*/
const int maxn = 2e6 + 10;

#define endl '\n'
namespace easy{
//	const int maxn = 5050;
	int x[maxn], dp[maxn], f[maxn], dis[maxn], n, d, rt[maxn];//到达 i 的距离、数量
	vector <int> G[maxn];
	void bfs(int s){
		queue <int> q;
		q.push(s);
		fir(i, 1, n) dis[i] = INT_MAX;
		dis[s] = 0;
		rt[s] = 1;
		bitset <maxn> vis;
		while(q.size()){
			int u = q.front();
			q.pop();
			if(vis[u]) continue ;
			vis[u] = 1;
			for(auto v : G[u]){
				if(dis[v] > dis[u] + 1){
					dis[v] = dis[u] + 1;
					rt[v] = rt[u];
					q.push(v);
				}
				else if(dis[v] == dis[u] + 1){
					rt[v] += rt[u];
				}
			}
		}
	}
	void main(){
		int c, t;
		cin >> c >> t;
		while(t--){
			cin >> n >> d;
			fir(i, 1, n) cin >> x[i];
			fir(i, 1, n) G[i].clear();
			fir(i, 1, n){
				fir(j, i + 1, n){
					if(x[j] - x[i] <= d){
						G[i].push_back(j);
					} 
				}
//			cout << "node " << i << " range = " << L[i] << ' ' << R[i] << endl;
			}
			int ans = 0;
			fir(i, 1, n){
				bfs(i);
				fir(j, i + 1, n){
					if(rt[j] == 2) ans++;
				}
			}
			cout << ans << endl;
			/*
			转移：dp[i][0] -> dp[j][0] （和 i 交集只有一个的 j）
			dp[i][1] -> dp[j][1] （和 i 交集只有一个的 j）
			dp[i][0] -> dp[j][1] （和 i 交集恰好有两个的 j）
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
			
			写成：
			dp[j][0] -> dp[i][0]
			*/
		}
	}
}
signed main(){
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	easy :: main();
//	int c, t;
//	cin >> c >> t;
//	while(t--){
//		int n, d;
//		cin >> n >> d;
//		fir(i, 1, n) cin >> x[i];
//		fir(i, 1, n){
//			int ll = 1, rr = i;
//			while(ll <= rr){
//				int mid = (ll + rr) >> 1;
//				if(x[i] - x[mid] > d) ll = mid + 1;
//				else rr = mid - 1, L[i] = mid;
//			}
//			ll = i, rr = n;
//			while(ll <= rr){
//				int mid = (ll + rr) >> 1;
//				if(x[mid] - x[i] > d) rr = mid - 1;
//				else ll = mid + 1, R[i] = mid;
//			}
////			cout << "node " << i << " range = " << L[i] << ' ' << R[i] << endl;
//		}
//		/*
//		转移：dp[i][0] -> dp[j][0] （和 i 交集只有一个的 j）
//		dp[i][1] -> dp[j][1] （和 i 交集只有一个的 j）
//		dp[i][0] -> dp[j][1] （和 i 交集恰好有两个的 j）
//		0 2
//		4 2
//		1 2 3 4
//		5 2
//		1 2 3 4 5
//		
//		0 2
//		5 3
//		-2 -1 0 1 2
//		6 2
//		-4 -3 -2 -1 3 6
//		
//		写成：
//		dp[j][0] -> dp[i][0]
//		*/
//		build(0, 1, 1, n, 1);
//		build(1, 1, 1, n, 0);
////		cout << "try " << query(1, 1, 1, 1) << endl;
//		fir(i, 1, n) dp[i][0] = 1, dp[i][1] = 0;
//		fir(i, 1, n){
////			cout << "### " << i << endl;
//			int low1 = lower_bound(R + 1, R + n + 1, L[i]) - R;
//			int high1 = upper_bound(R + 1, R + n + 1, L[i]) - R - 1;
//			if(R[low1] == L[i]){
////				cout << "type = 1 " << low1 << ' ' << high1 << endl;
//				dp[i][0] = query(0, 1, low1, min(i - 1, high1)); 
//				dp[i][1] += query(1, 1, low1, min(i - 1, high1));
//			}
//			int low2 = lower_bound(R + 1, R + n + 1, L[i] + 1) - R;
//			int high2 = upper_bound(R + 1, R + n + 1, L[i] + 1) - R - 1;
//			if(R[low2] == L[i] + 1) dp[i][1] += query(0, 1, low2, min(i - 1, high2));
//			update(0, 1, i, dp[i][0]);
//			update(1, 1, i, dp[i][1]);
////			cout << "try " << query(1, 1, 1, 1) << endl;
////			cout << endl;
////			cout << "array dp:";
////			for(int j = 1; j <= n; j++) cout << (int) dp[j][1] << ','; cout << endl;cout << "segtr:";
////			for(int j = 1; j <= n; j++) cout << query(1, 1, j, j) << ' '; cout << endl;
//		}
//		int ans = 0;
//		fir(i, 1, n) ans += dp[i][1];
////		cout << endl;
//		cout << ans << endl;
//	}
	return 0;
	
}
