#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
char ch;
long long ans;
struct ac
{
	long long num;
	char bj;
}sz[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&sz[i].num);
		while((ch=getchar())<'a'||ch>'z');
		sz[i].bj=ch;
	}
	for(int i=1,j=n;i<j;)
	{
		if(sz[i].bj==sz[j].bj)
		{
			if(sz[i].num>sz[j].num)
			{
				sz[i].num-=sz[j].num;
				j--;
			}
			else if(sz[i].num==sz[j].num)
			{
				i++;
				j--;
			}
			else if(sz[i].num<sz[j].num)
			{
				sz[j].num-=sz[i].num;
				i++;
			}
		}
		else
		{
			if(sz[i].num>sz[j].num)
			{
				ans+=sz[j].num;
				sz[i].num-=sz[j].num;
				j--;
			}
			else if(sz[i].num==sz[j].num)
			{
				ans+=sz[i].num;
				i++;
				j--;
			}
			else if(sz[i].num<sz[j].num)
			{
				ans+=sz[i].num;
				sz[j].num-=sz[i].num;
				i++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

