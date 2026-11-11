#include <iostream>
#include <cstdio>
using namespace std;
int n;
int ai;
char ci;
char c[1000010];
long long cnt;
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ai);
		scanf("%s",&ci);
		for(int j=1;j<=ai;j++)
		{
			c[++sum]=ci;
		}
	}
	if(sum%2==0)
	{
		for(int i=sum/2+1;i<=sum;i++)
		{
			if(c[i]!=c[sum-i+1])
			{
				cnt++;
			}
		}
	}
	else{
		for(int i=sum/2+2;i<=sum;i++)
		{
			if(c[i]!=c[sum-i+1])
			{
				cnt++;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}

