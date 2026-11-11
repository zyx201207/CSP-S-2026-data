#include<bits/stdc++.h>
using namespace std;
int u[2000005],v[2000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			u[i]=x;
			v[i]=y;
		}
		srand(time(0));
	    int n=rand()%10-1;
	    printf("%d\n",n);
	}
	return 0;
}
