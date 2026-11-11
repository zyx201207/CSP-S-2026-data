#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int f = 1, x = 0;
    int ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

const int N = 500010;
int w[N];
int c, n, m, d, q;
int goal = 0;
vector<pair<int, int> > a[500010];
int main()
{
	freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read();
    n = read();
    m = read();
    d = read();
    q = read();
    if(n == 1)
    {
    	for(int i = 1; i <= m; i++) w[i] = read();
	    for(int i = 1; i <= n; i++)
	    {
	    	int k = read();
	    	for(int j = 1; j <= k; j++)
	    	{
	    		int x = read(), y = read();
	    		a[i].push_back({x, y});
			}
		}
		while(q--)
		{
			int x = read(), y = read();
			int ans = INT_MAX;
			int flag11 = -1, flag12 = -1, flag21 = -1, flag22 = -1;
			for(int j = 0; j < a[1].size(); j++)
			{
				if(a[1][j].first == x)
				{
					flag11 = j;
				}
				if(a[1][j].first == y)
				{
					flag12 = j;
				}
			}
			ans = w[x] + w[y] + a[1][flag11].second + a[1][flag12].second;
			cout << ans << endl;
		}
		return 0;
	}
    if(n == 2)
    {
    	for(int i = 1; i <= m; i++) w[i] = read();
	    for(int i = 1; i <= n; i++)
	    {
	    	int k = read();
	    	for(int j = 1; j <= k; j++)
	    	{
	    		int x = read(), y = read();
	    		a[i].push_back({x, y});
			}
		}
		int minchange = INT_MAX;
		for(int i = 0; i < a[1].size(); i++)
		{
			for(int j = 0; j < a[2].size(); j++)
			{
				if(a[1][i].first == a[2][j].first)
				{
					minchange = min(minchange, a[1][i].second + a[2][j].second);
					break;
				}
			}
		}
		while(q--)
		{
			int x = read(), y = read();
			int ans = INT_MAX;
			int flag11 = -1, flag12 = -1, flag21 = -1, flag22 = -1;
			for(int j = 0; j < a[1].size(); j++)
			{
				if(a[1][j].first == x)
				{
					flag11 = j;
				}
				if(a[1][j].first == y)
				{
					flag12 = j;
				}
			}
			for(int j = 0; j < a[2].size(); j++)
			{
				if(a[2][j].first == x)
				{
					flag21 = j;
				}
				if(a[2][j].first == y)
				{
					flag22 = j;
				}
			}
			if(flag11 != -1 && flag12 != -1)
			{
				//cout << 11111111111 << endl;
				ans = min(ans, w[x] + w[y] + a[1][flag11].second + a[1][flag12].second);
			}
			if(flag21 != -1 && flag22 != -1)
			{
				//cout << 2222222222222 << endl;
				ans = min(ans, w[x] + w[y] + a[1][flag21].second + a[1][flag22].second);
			}
			if(flag11 != -1 && flag12 == -1)
			{
				//cout << 33333333333 << endl;
				ans = min(ans, w[x] + w[y] + a[1][flag11].second + a[2][flag22].second + minchange);
			}
			if(flag11 == -1 && flag12 != -1)
			{
				//cout << 44444444444 <<endl;
				ans = min(ans, w[x] + w[y] + a[1][flag12].second + a[2][flag21].second + minchange);
			}
			cout << ans << endl;
		}
		return 0;
	}
}
