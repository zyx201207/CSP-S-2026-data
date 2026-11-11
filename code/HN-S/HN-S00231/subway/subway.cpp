#include<bits/stdc++.h>
using namespace std;
#define int long long
int c , n , m , d , Q;
int w[500005];
int b[440][440] , a[500005] , t[500005] , f[500005] , vis[500005];
vector<int> q[500005];
vector<pair<int , int> > s[500005];
void spf(int k , int op)
{
	queue<int> h;
	h.push(k);
	for(int i = 1; i <= m; i ++)
	{
		f[i] = 1e18;
		vis[i] = 0;
	}
	f[k] = 0;
	while(!h.empty())
	{
		int g = h.front();
		h.pop();
		vis[g] = 0;
		for(int i = 0; i < q[g].size(); i ++)
		{
			int v , ew;
			if(op == 1)
			{
				v = q[g][i];
				ew = b[g][v];
			}
			else
			{
				v = s[g][i].first;
				ew = s[g][i].second;
			}
			if(f[g] + ew < f[v])
			{
				f[v] = f[g] + ew;
				if(vis[v] == 0)
				{
					vis[v] = 1;
					h.push(v);
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> Q;
	if(c <= 6)
	{
		for(int i = 1; i <= m; i ++)cin >> w[i];
		for(int i = 1; i <= n; i ++)
		{
			int k;
			cin >> k;
			for(int j = 1; j <= k; j ++)cin >> a[j] >> t[j];
			for(int j = 1; j <= k; j ++)
			{
				for(int o = 1; o <= k; o ++)
				{
					if(a[j] != a[o])
					{
						if(b[a[j]][a[o]] == 0)
						{
							b[a[j]][a[o]] = t[j] + t[o];
							q[a[j]].push_back(a[o]);
						}
						else b[a[j]][a[o]] = min(b[a[j]][a[o]] , t[j] + t[o]);
					}
				}
			}
		}
		while(Q --)
		{
			int x , y;
			cin >> x >> y;
			spf(x , 1);
			cout << f[y] + w[x] + w[y] << "\n";
		}
	}
	else if(c <= 11)
	{
		for(int i = 1; i <= m; i ++)cin >> w[i];
		for(int i = 1; i <= n; i ++)
		{
			int k;
			cin >> k;
			for(int j = 1; j <= k; j ++)cin >> a[j] >> t[j];
			if(k == 2)
			{
				pair<int , int> x1 , x2;
				x1.first = a[2];
				x1.second = t[1] + t[2];
				x2.first = a[1];
				x2.second = t[1] + t[2];
				s[a[1]].push_back(x1);
				s[a[2]].push_back(x2);
			}
		}
		while(Q --)
		{
			int x , y;
			cin >> x >> y;
			spf(x , 2);
			cout << f[y] + w[x] + w[y] << "\n";
		}
	}
	return 0;
}
