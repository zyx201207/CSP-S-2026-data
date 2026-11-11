#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10, M = 40;
int n, m, ans, maxn = -1;
int a[N];
struct Node{
	int id, maxv;
} b[N];
int get(int n)
{
	int cnt = 0;
	while(n)
	{
		n /= 2;
		cnt ++;
	}
	return cnt;
}
int cmp(Node x, Node y)
{
	if(x.maxv == y.maxv) return a[x.id] > a[y.id];
	return x.maxv > y.maxv;
}
void dfs(int pos, int num, int sum)
{
	if(pos == n) 
	{
		if(num != m) return;
		ans = max(ans, sum);
	}
	if(num > m) return;
	dfs(pos + 1, num + 1, sum + a[pos]);
	dfs(pos + 1, num, sum);
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if(n <= 20)
	{
		dfs(1, 0, 0);
		cout << ans << endl;
	}	
	else 
	{
		for(int i = 1; i <= n; i ++)
		{
			b[i].maxv = get(a[i]);
			b[i].id = i;
		}
		sort(b + 1, b + n + 1, cmp);
		ans = a[b[1].id];
		int possible = b[m].maxv;
		for(int i = 2; i <= m; i ++)
		{
			
			ans &= a[b[i].id];
		}
		cout << ans << endl;
	}
	return 0;
}
