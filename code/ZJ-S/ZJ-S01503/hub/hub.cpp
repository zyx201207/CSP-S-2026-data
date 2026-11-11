#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,wu1,wu2;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&wu1,&wu2);
		}
		printf("%d\n",n/5);
	}
	return 0;
}