#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
int c,t,n,k;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(int i=1;i<n;++i)
		{
			int x,y;
			scanf("%d %d",&x,&y);
		}
		if(k==n)
			printf("0\n");
		else if(k>=n/2)
			printf("1\n");
		else
		{
			n=n/2;
			n=(n+1)/2;
			k=(k+1)/2;
			printf("%d\n",(n-k+1)/2+1);
		}
	}
	return 0;
}
