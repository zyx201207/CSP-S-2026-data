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
vector<pair<int, int> > a[500010];
int main()
{
    c = read();
    n = read();
    m = read();
    d = read();
    q = read();
    for(int i = 1; i <= m; i++) w[i] = read();
    for(int i = 1; i <= n; i++)
    {
    	int k = read();
    	for(int j = 1; j <= (k << 1); j++)
    	{
    		int x = read(), y = read();
    		a[i].push_back({x, y});
		}
	}
	while(q--)
	{
		int ans = 0;
		int x = read(), y = read();
		for(int i = 1; i <= n; i++)
		{
			if(a[i].size() == 2)
			{
				if(a[i][0].first == x && a[i][1].first == y || a[i][0].first == y && a[i][1].first == x)
				{
					int tans = 0;
					tans = w[x] + w[y] + a[i][0].second + a[i][1].second;
					ans = min(ans, tans);
				}
			}
		}
		cout << ans << endl;
	}
    return 0;
}
