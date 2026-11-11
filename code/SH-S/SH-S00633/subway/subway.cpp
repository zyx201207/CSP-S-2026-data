#include<bits/stdc++.h>
using namespace std;



vector<int> g[2000005];
int dis[20005][20005];
int a[2000005];
int ton[2000005];


int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n>>m>>d>>q;
	int idx = n+1;
	for(int i = 1;i<=n;i++)
	{
		int num;
		cin >> num;
		int v;
		for(int j = 1;j<=num;j++)
		{
			
			cin >> u>>w;
			if(j==1)
			{
				g[u]=w;
				v=u;
				continue;
			}
			g[v].push_back(idx);
			g[idx].push_back(v);
			a[idx]=w;
			ton[u]=idx;
			v=idx;
			idx++;
		}
	}
	
	return 0;
}
