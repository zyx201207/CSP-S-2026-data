#include <bits/stdc++.h>
using namespace std;
const int maxn =  1e6+2;
int fu[maxn];
int G[maxn][maxn];
int c,t,n,k;

void init(int x)
{
	for(int i = 1;i <= x;i++)
		fu[i] = i;
}
int find(int x)
{
	if(fu[x] = x)
		return x;
	else
	{
		fu[x] = find(fu[x]);
		return fu[x];
	}
}
void unionn(int x,int y)
{
	int i = find(x);
	int j = find(y);
	fu[i] = j;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		init(n);
		for(int i = 1;i < n;i++)
		{
			int u,v;
			cin >> u >> v;
			G[u][v] = G[v][u] = 1;
			unionn(u,v);
		}
		
	}
	return 0;
}
//Oct31==Dec25 
