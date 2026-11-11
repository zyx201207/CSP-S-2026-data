#include<bits/stdc++.h>
using namespace std;
#define N 200005
struct ff{
	int num;
	char c;
}a[N];
int n;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i].num,&a[i].c);
	}
	int l=1,r=n,t=0;
	while(l<=r)
	{
		if(a[l].c==a[r].c)
		{
			if(a[l].num<a[r].num)
			{
				a[r].num-=a[l].num;
				a[l].num=0;
			}
			else
			{
				a[l].num-=a[r].num;
				a[r].num=0;
			}
		}
		else
		{
			int sum=min(a[l].num,a[r].num);
			ans+=sum;
			a[l].num-=sum;
			a[r].num-=sum;
		}
		while(a[l].num==0)
		{
			l++;
		}
	 	while(a[r].num==0)
		{
			r--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
