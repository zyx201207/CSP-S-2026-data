#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
vector<int> G[maxn]; 
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while(t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		for(int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	return 0;
}
