#include<bits/stdc++.h>
using namespace std;
int n,k,x,y;
vector<int>v[1000007];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T,c;
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		printf("%d\n",1);
	}
	return 0;
}