#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10, M = 1e5 + 10;

int c, n, m, d, q;
int w[N];
int a[520][N], t[520][N];
int k[N];
int x[M], y[M];
int op[N];

long long dfs(int cnt, int zhan, int qi, int zhong)//luxian, zhantai, qidian, zhongdian
{
	long long que = 1e13;
	
	zhan++;//xiayizhan
	if(a[cnt][zhan] == zhong)
		return t[cnt][zhan];
	if(a[cnt][zhan] > zhong)
		return -1;
	if(a[cnt][zhan] == 0)
		return -1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= k[i]; j++)
		{
			if(a[i][j] == a[cnt][zhan] && i != cnt && op[i] == 0)
			{
				op[i] = 1;
				long long we = dfs(i, j, a[cnt][zhan], zhong);
				if(we != -1)
					que = min(que, we + t[i][j] + t[cnt][zhan]);
				op[i] = 0;
			}
			else if(a[i][j] == a[cnt][zhan] && i == cnt)
			{
				op[i] = 1;
				long long we = dfs(i, j, a[cnt][zhan], zhong);
				if(we != -1)
				que = min(que, we);
				op[i] = 0;
			}
		}
	}
	return que;
}

long long zhao(int qi, int zhong)
{
	long long que = 1e13;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= k[i]; j++)
		{
			if(a[i][j] == qi)
			{
				op[i] = 1;
				long long we = dfs(i, j, qi, zhong);
				//if(we != -1)
					que = min(que, we + t[i][j]);
				op[i] = 0;
			}
		}
	}
	return que;
}

void suan(int qi, int zhong)
{
	long long ans = 0;
	ans += w[qi] + w[zhong];
	long long op = zhao(qi, zhong);
	ans += op;
	cout << ans << endl;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	for(int i = 1; i <= q; i++)
	{
		cin >> x[i] >> y[i];//qidian zhongdian		
		suan(x[i], y[i]);
	}
		
	return 0;
}
