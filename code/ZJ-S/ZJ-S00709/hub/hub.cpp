#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,k;
vector<int> p[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			p[u].push_back(v);
			p[v].push_back(u);
		}
		int m=n+3>>1;
		if(k==n)
		{
			printf("0\n");
			continue;
		}
		if(k==1)
		{
			printf("%lld\n",m>>1);
			continue;
		}
		printf("%lld\n",(m-k-1)/4+1);
		
	}
	return 0;
}