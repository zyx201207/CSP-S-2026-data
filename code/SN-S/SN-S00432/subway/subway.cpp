#include<bits/stdc++.h>
using namespace std;
struct edge2
{
	long long child, cost;
};
struct edge
{
	int w; 
	int count_child;
	vector<edge2>child;
};
edge V[500005];
long long c, n, m, d, q;

int main()
{
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> V[i].w;
	for(int i = 1; i <= n; i++)
	{
		cin >> V[i].count_child;
		for(int j = 1; j <= V[i].count_child; j++)
		{
			long long tempin1;
			long long tempin2;
			cin >> tempin1;
			cin >> tempin2;
			V[j].child.push_back({tempin1, tempin2});
			V[tempin1].child.push_back({j, tempin2});
		}
	}for(int i = 1; i <= q; i++)
	{
		long long x, y;
		
	}
	return 0;
}
