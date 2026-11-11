#include<bits/stdc++.h>
using namespace std;
struct s
{
	long long z,pd;
}a[500010];
long long t[100];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++)
    {
		scanf("%lld",&a[i].z);
		a[i].pd=a[i].z;
	}
	long long t1=0,t2=0;
	for(long long i=1;i<=n;i++)
	{
		t1=t2=0;
		if(i>1)
		{
			for(long long j=1;j<=n;j++)
			{
				a[j].pd=a[j].z;
			}
		}
		for(long long j=i;j<=n;j++)
		{
			if(a[j].pd==1)
			{
				if(t1==0)
				{
					t1=j;
				}
				else
				{
					for(long long k=t1;k<j;k++)
					{
						a[k].pd=0;
					}
				}
			}
			if(a[j].pd==2)
			{
				if(t2==0)
				{
					t2=j;
				}
				else
				{
					for(long long k=t1;k<j;k++)
					{
						a[k].pd=0;
					}
				}
			}
		}
		for(long long j=1;j<=n;j++)
		{
			t[a[j].pd]++;
		}
	}
	for(long long i=1;i<=m;i++)
	{
		printf("%lld ",t[i]);
	}
    return 0;
}
