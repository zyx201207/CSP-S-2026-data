#include <bits/stdc++.h>
#include <string>
int len[20000005];
char s[20000005];
using namespace std;
int main()
{	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int r=0;
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&len[i]);
		scanf("%a%c",&s[i]);
	}
	if(a==1)
	{
		printf("%d",0);
	}else if(a==2)
	{
		if(len[1]<len[2])
		{
			printf("%d",len[1]);
		}else
		{
			printf("%d",len[2]);
		}
	}else
	{
		bool ok=1;
		for(int i=1;i<=a;i++)
		{
			if(len[i]!=1)
			{
				ok=0;
				break;
			}
		}
		if(ok!=0)
		{
			printf("%d",a/2);
			r=1;
		}
	}
	if(r!=1)
	{
		printf("%d",a/2);
	}
	return 0;
}
