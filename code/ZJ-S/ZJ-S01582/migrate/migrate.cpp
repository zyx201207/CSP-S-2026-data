#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int c, t;
int n, d;
int x[N], res;
typedef pair<int, int> PII;
queue<PII> q;
int tmp[N];

bool check1() //存在点能直接到达任意一点 
{
	for(int i = 1; i <= n; i ++)
		if(x[n] - x[i] <= d && x[i] - x[1] <= d)
			return true;
	return false;
}
bool check2() //等差
{
	int f = x[2] - x[1];
	for(int i = 3; i <= n; i ++)
		if(x[i] != x[i - 1] + f)
			return false;
	return true;
}
int calc(int u, int v)
{
	if(u == v) return 0;
	int t = x[u] + d;
	for(int i = u; i <= v; i ++)
		if((x[i] <= t && x[i + 1] > t) || i == v)
		{
			q.push({i, x[i] - x[u]});
			res ++;
			calc(i, v);
			break;
		}
	return res;
}
bool same(int id)
{
	for(int i = 1; i <= id ; i ++)
		if(tmp[i] != tmp[i - 1])
			return false;
	return true;
}
bool check(int u, int v)
{
	int s = x[v] - x[u];
	int num = calc(u, v);
	int id = 0;
	while(q.size())
	{
		tmp[id ++] = q.front().second;
		q.pop();
	}
	if(same(id)) return false;
	return true;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) cin >> x[i];
		if(d >= (x[n] - x[1]) || n <= 3 ||check1())
		{
			puts("0");
			continue;
		}
		else if(check2())
		{
			int f = x[2] - x[1];
			if(d >= 2 * f) cout << n - (d / f + 1) << endl;
			else puts("0");
			continue;
		}
		int ans = 0;
		for(int i = 1; i < n - 1; i ++)
			for(int j = i + 2; j <= n; j ++)
				if(check(i, j))
					ans ++;
		cout << ans << endl;
	}
	return 0;
}
