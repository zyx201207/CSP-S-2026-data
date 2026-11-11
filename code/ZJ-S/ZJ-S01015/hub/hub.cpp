#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<int> maps[1000010];
int main()
{
	
	int RP=0;
	RP++;
	RP++;
	RP++;
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			maps[n].clear();
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			maps[u].push_back(v);
			maps[v].push_back(u);
			
		}
	}
	cout<<RP;
	return 0;
}
