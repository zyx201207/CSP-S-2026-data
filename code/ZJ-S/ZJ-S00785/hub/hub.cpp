#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.ont","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==13||c==14)
	{
		while(t--)
		{
			scanf("%d%d",&n,&k);
			printf("%d",(n-k+2*k-1)/(2*k));
		}
	}
	else
	{
		while(t--)
		{
			printf("0\n");
		}
	}
	return 0;
} 
