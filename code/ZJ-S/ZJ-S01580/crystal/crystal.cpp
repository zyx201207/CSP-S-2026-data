#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int n,cnt,maxx,vis=1;
long long m,a[M],sum,c[M],cc;
inline bool cmp(int q,int p)
{
	return q>p;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=3;i<=n;i++) if(a[i-1]-a[i-2]!=a[i]-a[i-1])
	{
		vis=0;
	}
	if(n>5000&&vis==1)
	{
		sum=a[2]-a[1];
		m/=sum;
		m/=2;
		for(int i=1;;i++) 
		{
			cnt+=i;
			if(cnt>m)
			{
				if(n%2==1)
				{
					printf("%d\n",i*2-1);
				}
				else
				{
					printf("%d\n",i*2-2);
				}
				return 0;
			}
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		sum=cnt=0;
		for(int j=i;j<=n;j++)
		{
			sum+=(a[i]-a[j]);
			if(sum<=m)
			{
				cnt++;
				maxx=max(maxx,cnt);
			}
			else
			{
				break;
			}
		}
	} 
	printf("%d\n",maxx);
	return 0;
}
