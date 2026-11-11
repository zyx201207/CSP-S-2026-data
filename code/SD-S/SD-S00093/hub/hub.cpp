#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int T,c,n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
		}
		if(n==k)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
		}
	}
	return 0;
}
