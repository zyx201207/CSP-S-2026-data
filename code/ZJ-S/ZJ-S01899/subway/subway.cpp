#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 507
#define M 500007
#define K 500007
#define INF 0x3f3f3f3f3f3f3f3f
#define input input4g32ugyg52hgjg352

template<class T> void input(T &a)
{
    a = 0;
    int ch = getchar();
    while (ch < '0') ch = getchar();
    while (ch >= '0')
    {
        a = (a << 1) + (a << 3) + (ch & 15);
        ch = getchar();
    }
}

int c, n, m, d, q;
int w[M];
int k[N];
vector<pair<int, int> > t[M];
vector<int> jingguo[M];

int edge[N][N];

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    input(c); input(n); input(m); input(d); input(q);
    for (int i = 1; i <= m; i++) input(w[i]);
    for (int i = 1; i <= n; i++)
    {
        input(k[i]);
        int tmp1, tmp2;
        for (int j = 0; j < k[i]; j++)
        {
            input(tmp1); input(tmp2);
            t[tmp1].push_back({i, tmp2});
            jingguo[tmp1].push_back(i);
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            edge[i][j] = INF;
        }
    }
    for (int i = 0; i <= n; i++) edge[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (auto j = t[i].begin(); j < t[i].end(); j++)
        {
        	auto l = j;
            for (l++; l < t[i].end(); l++)
            {
                edge[j->first][l->first] = min(edge[j->first][l->first], j->second + l->second);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
    	for (int j = 1; j <= n; j++)
    	{
    		edge[i][j] = edge[j][i] = min(edge[i][j], edge[j][i]);
		}
	}
    for (int k = 1; k <= n; k++)
    {
    	auto tmpk = edge[k];
        for (int i = 1; i <= n; i++)
        {
        	auto tmp = edge[i];
            for (int j = 1; j <= n; j++)
            {
                tmp[j] = min(tmp[j], tmp[k] + tmpk[j]);
            }
        }
    }
    while (q--)
    {
        int x, y;
        input(x); input(y);
        int ans = INF;
        for (auto i: t[x])
        {
        	auto tmp2 = edge[i.first];
        	int nans = INF;
            for (auto j: t[y])
            {
            	nans = min(nans, tmp2[j.first] + j.second);
            }
            ans = min(ans, nans + i.second);
        }
        printf("%lld\n", w[x] + ans + w[y]);
    }
    return 0;
}
