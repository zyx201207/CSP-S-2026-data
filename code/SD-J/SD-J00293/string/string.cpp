#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int N=2e5+10;
struct st{
	long long a;
	char ch;
}str[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0,mid=0,sum=0;
	scanf("%lld",&n);
	for(int i=0;i<=n-1;i++)
	{
		scanf("%lld  %c  ",&str[i].a,&str[i].ch);
		num+=str[i].a;
	}
	for(int i=0;i<=n-1;i++)
	{
		sum+=str[i].a;
		if(sum==num/2)
		{
			mid=i; 
			break;
		}
	}
	sum=0;
	int l=0,r=n-1;
	while(l<r)
	{
		int minn=min(str[l].a,str[r].a);
		str[l].a-=minn;
		str[r].a-=minn;
		if(str[l].ch!=str[r].ch)
			sum+=minn;
		if(str[l].a==0)
			l++;
		if(str[r].a==0)
			r--;
	}
	printf("%lld",sum);
	return 0;
}
