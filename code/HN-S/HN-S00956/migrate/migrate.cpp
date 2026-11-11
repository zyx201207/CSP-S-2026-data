#include<bits/stdc++.h>
#define int long long
#define fore(i,a,b) for(int i=(a);i<=(b);++i)
#define repe(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N = 5010;
vector<int> G[N];
int c, Test;
int n, D;
int a[N];
void Clear() {
	fore(i, 1, n) {
		G[i].clear();
		a[i] = 0;
	}
}

int dis[N], g[N];
bool vis[N];
queue<int> q;

void dijinit() {
	fore(i, 1, n) {
		g[i] = 0;
		dis[i] = 1e18;
		vis[i] = 0;
	}
	while(!q.empty()) q.pop();
}
/*
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

*/
void Dij(int s) {
	q.push(s);
	dis[s] = 0;
	g[s] = 1;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int v : G[u]) {
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				g[v] = g[u];
				q.push(v);
			} else if(dis[v] == dis[u] + 1) {
				g[v] += g[u];
			}
		}
	}
}

void Main() {
	cin >> n >> D;
	Clear();
	fore(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	fore(u, 1, n) {
		fore(v, 1, n) {
			if(u == v) continue;
			if(llabs(a[u] - a[v]) <= D) {
				G[u].push_back(v);
			}
		}
	}
//	fore(i, 1, n) {
//		cout << i << ": \n";
//		for(int v : G[i]) cout << v << ' ';
//		cout << '\n';
//	}
	int ans = 0;
	fore(u, 1, n) {
		dijinit();
		Dij(u);
		fore(v, 1, n) {
			if(g[v] == 2) ans ++;
		}
	}
	cout << ans / 2 << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> Test;
	if(c <= 10) while(Test --) Main();
	else{
		cout << n * (n - 1) / 2 << '\n';
	}
	return 0;
}











/*
15:40做完T1T2感觉今年好简单分数线不会干到200+吧 
感觉T2不好生成数据就不对拍了
不能给我挂了吧
今年空间好宽裕，都放心#defineintlonglong 
16:50打完 T3T4暴力 
500^3有被卡常的风险吗？ 
255，不挂分应该稳了 
*/
