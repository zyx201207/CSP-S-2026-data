#include <bits/stdc++.h>
#define int long long
using namespace std;
int re()
{
	char ch = getchar();
	int sum = 0, p = 1;
	while(!isdigit(ch)){if(ch == '-')p = -1; ch = getchar();}
	while(isdigit(ch)){sum = sum * 10 + (ch - '0'); ch = getchar();}
	return sum * p;
}
const int N = 2e6 + 5, INF = 1e9;
int n, c, k, ans, vis[N];
vector<int> G[N];
int calc()
{
	int tmpd[15] = {0}, VIS[15] = {0};
	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i]) tmpd[i] = INF;
		else q.push(i), VIS[i] = 1;
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v : G[u])
			if(!VIS[v]) tmpd[v] = tmpd[u] + 1, VIS[v] = 1, q.push(v);
	}
	int res = 0;
	for(int i = 1; i <= n; i++)
		res = max(res, tmpd[i]);
	return res;
}
void brute(int dep)
{
	if(dep > n) 
	{
		int cnt = 0, flg = k;
		for(int i = 1; i <= n; i++)
			if(vis[i]) cnt++;
		if(cnt != k) return ;
		for(int i = 1; i <= n; i++)
		{
			if(!vis[i]) continue;
			for(auto v : G[i])
			{
				if(v < i) continue;
				if(vis[v]) flg--;
			}
		}
		if(flg > 2) return ;
		ans = min(ans, calc());
		return ;
	}
	vis[dep] = 1;
	brute(dep + 1);
	vis[dep] = 0;
	brute(dep + 1);
}
void clear(){for(int i = 1; i <= n; i++) vis[i] = 0, G[i].clear();}
void sol()
{
	n = re(), k = re(), ans = n + 1;
	for(int i = 1; i < n; i++)
	{
		int u = re(), v = re();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(c <= 3) brute(1), cout << ans << "\n";
	else if(c == 13 || c == 14)
	{
		int m = (n - 1) / 2;
		if(k == n) cout << "0\n";
		else if(k >= m) cout << "1\n";
		else if(k == 1) cout << (m + 2) / 2 << "\n";
		else 
		{
			int l = 2, r = (m + 2) / 2;
			while(l <= r)
			{
				int mid = (l + r) >> 1;
				int XX = (k - 2) / 2, YY = k - XX;
				int L = (m - mid + 2 - YY - mid - XX);
				if(L / 2 + 1 <= mid) r = mid - 1;
				else l = mid + 1;
			}
			cout << l << "\n";
		}
	}
	clear();
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	c = re(); int T = re();
	while(T--) sol();
	return 0;
}
