#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 305;
const int M = 2000005;
int n, cid, f[N][N], la[M], ne[M];
ll a[M], d, ans;
int dp[N][N];
inline void clean () {
	ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = 0;
			f[i][j] = 0;
		}
		la[i] = 0;
	}
	return;
}
inline void check (int pl, int pr) {
	if (pr - pl <= 2) return;
	int lpos = pl;
	for (int i = pl; i <= pr; i++) {
		while (a[i] - a[lpos] > d) lpos++;
		la[i] = lpos;
	}
	for (int i = pl; i <= pr; i++) {
		for (int j = i; j <= pr; j++) {
			if (a[j] - a[i] <= d) {
				f[i][j] = 1;
				dp[i][j] = 1;
			} else {
				f[i][j] = f[i][la[j]] + 1;
			}
		}
	}
	for (int l = pl; l <= pr; l++) {
		for (int r = l + 1; r <= pr; r++) {
			if (dp[l][r] == 1) {
				continue;
			}
			for (int k = la[r]; k < r; k++) {
				if (f[l][k] == f[l][r] - 1) {
					dp[l][r] += dp[l][k];
					dp[l][r] = min (dp[l][r], 3);
				}
			}
		}
	}
	for (int i = pl; i <= pr; i++) {
		for (int j = i + 1; j <= pr; j++) {
			if (dp[i][j] == 2) ans++;
		}
	}
	return;
}
inline void solve1 () {
//	cout<<a[2]-a[1]<<"???\n";
//	cout<<"2857391858419"<<"!!!\n";
	if (cid == 11 or cid == 12) {
		if (a[2] - a[1] > d) {
			cout << "0\n";
			return;
		}
		//看看最远走几个 
		int pos = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] - a[1] > d) {
				pos = i - 2;
				break;
			}
		}
		if (pos <= 1) {
			cout << "0\n";
			return;
		}
		if ((pos << 1) >= n - 1) {
			cout << "0\n";
			return;
		}
		pos <<= 1;
		pos--;
		cout << n - pos << "\n";
	} else if (cid == 13 or cid == 14) {
		int pos = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] - a[1] <= d and a[n] - a[i] <= d) {
				if (!pos) {
					pos = i;
				} else {
					cout << "0\n";
					return;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			la[i] = 0;
			ne[i] = 0;
		}
		int ptr = 1;
		for (int i = 1; i <= n; i++) {
			while (a[i] - a[ptr] > d) ptr++;
			la[i] = ptr;
		}
		ptr = n;
		for (int i = n; i >= 1; i--) {
			while (a[ptr] - a[i] > d) ptr--;
			ne[i] = ptr;
		}
		ll v1 = 0, v2 = 0;
		for (int i = 1; i <= n; i++) {
			if (ne[i] == pos) {
				v1++;
			}
			if (la[i] == pos) {
				v2++;
			}
		}
		cout << v1 * v2 << "\n";
	}
	return;
}
inline void solve () {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n > 300) {
		solve1 ();
		return;
	}
	clean ();
	int lst = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] > d) {
			check (lst, i - 1);
			lst = i;
		}
	}
	check (lst, n);
	cout << ans << "\n";
	return;
}
int main () {
//	freopen ("migrate3.in", "r", stdin);
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	int T;
	cin >> cid >> T;
	while (T--) {
		solve ();
	}
	return 0;
}
/*
14:38 已经100分 还有3小时52分钟 
15:23 已经200分 还有3小时7分钟 
目标300+ 加油！！ 
路径长度取决于经过了几个点 
如果某两个点u,v,u<v之间的最短路径恰好有2条 
这就是一个合法数对 
求出有几对 n<=2e6 要用线性或者低常数带log做法 
先想一下暴力O(N^2)
如果最短路径计数就是2 
一定是u->mid->v和u->mid+1->v 而且v-u>2 
u,v下标差越小 其最短距离越小 
可能还会出现不连通的情况 这种我们必须分开解决 
如何计算最短距离？ 
直接不断跳就行 
我们先找到最小单位 距离为2的 这种情况一定是x->mid->y,x->mid+1->y 
而且x能一步到达的最远点是mid+1 y能一步到达的最远点是mid 
而且x,y位置之差大于d 
这个可以双指针预处理 
那么如何判断两点之间是否最短路径唯一？ 
不断跳然后检测一下是否双向成立 也就是检查x,y是否互为最远点 
只要检测失败 立刻退出 
可以尝试检测某个点为终点/起点的情况下，有多少个点路径唯一 
只要能预处理左右有几个最短路唯一点 这就是正解 
思考预处理方法 
发现检测最短路径是否唯一并没有那么简单 上面的思路错误 
16:02还剩2小时28分钟 
考场在8楼来的时候电梯好像还出故障了。。。 爬上来的 
检测条件：如果距离为dis 那么前dis-1个位置必须严格满足双向对应关系 
最后一个位置只要对面最只能到达这里就可以 这里是不是最远只能到达对面无所谓 
我们可以记录一下每个点左边或者右边有几个点最远到达此处 
也可以O(n)预处理 
关键是怎么确定到哪里出现第二个非双向最远点对 
就是找到第一个位置 使得能够最远到达该点的点数量=0
争取拿满分 
0 1
8 3
0 1 2 4
最晚到17:30
8 10 11 13
放弃满分专攻O(N^2) 时间不多了还有1小时47分钟 
f[i][j]表示i到达j的最短路距离 
可以O(n^2) 
下一步怎么做 
O(N^2)暴力 
还是想办法检测两点是否路径唯一 
想不出来 只能O(n^3)暴力 
17:20拿下224分 
思考等差数列做法 
17:42 232分 
思考性质B 
怎么做 最远距离为2 
对于距离为2的部分 我们可以检测一下是不是只有一条路 
思考7分钟 
枚举左端点 只要他最远可直接到达的点不是特定点 
就不用搜了 
*/
