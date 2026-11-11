/*
-------a---b---c---d------>
前几个点的暴力: 
如果 x_i 到 x_j 和 x_k 的距离都满足且 x_j 和 x_k 到 x_l 都是一步那么有两种 
即对于 x_u x_v 只用一步飞行可以选的岛屿 t 满足 x_t 在 [x_v - d, x_u + d]
可预处理得到若干个 (u, v) 就可以把坐标轴分割为若干段 
对于每个 (u, v) 设上一个 (u, v) 叫 (a, b) 下一个叫 (c, d) 那 [b + 1, u] 走法唯一 [v, c - 1] 走法唯一由于通过 (u, v)所以正好有两种
那么这一段贡献就是 (u - b) * (c - v) 不能跨段不然就是 4 种及以上走法了
复杂度: 预处理: O(N(枚举u)*N(枚举找到v)*logN(找(u, v)上有多少个t)) = O(N^2logN)
		统计答案: O(N(段数)*1(直接相乘得答案)) = O(N)
		总计: O(T(N+N^2logN)) -> /25*100=40pts
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000005;
void Main(int c);
void solve1();
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--)
		Main(c);
	return 0;
}


void Main(int c)
{
	if (c <= 10)
		solve1();
}

void solve1()
{
//	cout << "\n\n\n\nThis time: \n";
	int n;
	int d;
	cin >> n >> d;
	vector<int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	int ans = 0;
	auto get = [&](int L, int R) -> void
	{
		vector<pair<int, int>> fd;
		for (int u = L; u <= R; u++)
		{
			for (int v = u + 3; v <= R; v++)
			{
				int low = x[v] - d, high = x[u] + d;
				if (low >= high)
					break;
				int l = lower_bound(x.begin() + u, x.begin() + v, low) - x.begin();  // >=low
				int r = upper_bound(x.begin() + u, x.begin() + v, high) - x.begin() - 1; // <=high
				if (r - l + 1 == 2)
				{
					fd.push_back({u, v});
					u = v;
					break;
				}
			}
		}
//		cout << "fd : size : " << fd.size() << '\n';
//		for (auto tp : fd)
//			cout << "[" << tp.first << ", " << tp.second << "]\n";
		for (int i = 0; i < fd.size(); i++)
		{
			auto lst = (i - 1 >= 0) ? (fd[i - 1]) : make_pair(L - 1, -1ll);
			auto now = fd[i];
			auto nxt = (i + 1 < fd.size()) ? fd[i + 1] : make_pair(R + 1, -1ll);
			int a = lst.first, b = lst.second;
			int u = now.first, v = now.second;
			int c = nxt.first, d = nxt.second;
			ans += (u - b) * (c - v);
		}
		return;
	};
	vector<pair<int, int>> FD;
	int lst = 0;
	for (int i = 0; i < n;)
	{
		int nw = x[i];
		int nxt = nw + d;
		auto pos = upper_bound(x.begin() + i, x.end(), nxt) - x.begin() - 1;
		if (pos > i)
			i = pos;
		else
		{
			FD.push_back({lst, i});
			lst = i + 1;
			i++;
		}
	}
	if (lst < n - 1)
		FD.push_back({lst, n - 1});
	for (auto tp : FD)
	{
//		cout << "FD : [" << tp.first << ", " << tp.second << "]\n";
		get(tp.first, tp.second);
		
	}
//	cout << "ans : ";
	cout << ans << '\n';
}


