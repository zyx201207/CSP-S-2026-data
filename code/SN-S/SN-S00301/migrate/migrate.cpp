//不是哥们，我会T3了？
//这个题难度应该到不了ST3吧，或者说局面会和24年一样，T4是黑
//推一推性质可以发现，找一组相邻点来算贡献肯定是很好的
//然后把前后缀的纯单路径得算出来
//算的思路差不多，但是我感觉纯单路径稍微难算一点
//一个小时应该可以写完，五点四十进军T4
//唉可惜了，没能调出来，T4也没打几分
//100+100+8+15可能就是我最后一次CSP的成绩了 
#include<bits/stdc++.h>

using namespace std;

#define N 2000005
#define int long long
#define lowbit(x) (x & -x)

int n, d, a[N], ans;
int f[N], sumf[N], pre[N], suf[N];

struct BIT
{
	int tr[N];
	void init(){for(int i = 1; i <= n; i++)tr[i] = 0;}
	void modify(int pos, int val){for(int i = pos; i <= n; i += lowbit(i))tr[i] += val;}
	int query(int pos){int ans = 0; for(int i = pos; i; i -= lowbit(i))ans += tr[i]; return ans;}
	void update(int l, int r, int val){if(l > r)return; modify(l, val); if(r < n)modify(r + 1, -val);}
}Tr;

pair<int, int> find(int vl, int vr)
{
	//找到属于[vl,vr]的下标连续段
	int r = upper_bound(a + 1, a + n + 1, vr) - a - 1;
	int l = lower_bound(a + 1, a + n + 1, vl) - a;
	return {l, r}; 
}

void DP()
{
	for(int i = 1; i <= n; i++)f[i] = sumf[i] = 0;
	//注意转移f的时候，不要包含长度为0即(u,u)的单路径
	for(int i = 2; i <= n; i++)
	{
		pair<int, int> p;
		if(i < n)p = find(a[i] - d, min(a[i] - 1, a[i + 1] - d - 1));
		else p = find(a[i] - d, a[i] - 1);
		if(p.first > p.second)continue;
		f[i] += p.second - p.first + 1;
//		if(p.first == p.second)continue;
		int m = p.first;
		p = find(a[m] - d, a[m + 1] - d - 1);
		f[i] += sumf[p.second] - sumf[p.first - 1];
		sumf[i] = sumf[i - 1] + f[i];
	}
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T >> T;
	while(T--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)cin >> a[i];
		DP();
		for(int i = 1; i <= n; i++)pre[i] = f[i] + 1;
		for(int i = 1, j = n; i < j; i++, j--)a[i] *= -1, a[j] *= -1, swap(a[i], a[j]);
		if(n % 2 == 1)a[(n + 1) / 2] *= -1;
		DP();
		for(int i = 1, j = n; i < j; i++, j--)a[i] *= -1, a[j] *= -1, swap(a[i], a[j]);
		if(n % 2 == 1)a[(n + 1) / 2] *= -1;
		for(int i = 1; i <= n; i++)suf[n + 1 - i] = f[i] + 1;
		Tr.init();
		for(int i = n - 1; i >= 1; i--)suf[i] += suf[i + 1];
		for(int m = 2; m <= n - 2; m++)
		{
			pair<int, int> p1, p2; int l1, r1, l2, r2;
			p1 = find(a[m + 1] - d, a[m + 2] - d - 1);
			p2 = find(a[m - 1] + d + 1, a[m] + d);
			l1 = p1.first, r1 = p1.second, l2 = p2.first, r2 = p2.second;
			if(l1 > r1 || l2 > r2)continue;
			Tr.update(l1, r1, suf[l2] - suf[r2 + 1]);
		}
		ans = 0;
		for(int i = 1; i <= n; i++)
			ans += pre[i] * Tr.query(i);
		cout << ans << "\n";
	}
	return 0;
} 
