#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,M=(1ll<<40)-1;
int n,m,a[N],ans,f[40],sum=M,maxj,maax;
int final[1050];
bool f1=1,f2=1;
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maax=max(maax,a[i]);
		for(int j=0;(1<<j)<=a[i];j++)
		{
			maxj=max(maxj,j);
			if((a[i]>>j)&1)
			{
				f[j]++;
			}
			else
			{
				f1=0;
			}
		}
		if(i!=1&&a[i]!=a[i-1]+1)
		{
			f2=0;
		}
		sum&=a[i];
	}
	if(n<=20)
	{
		for(int st=1;st<(1<<n);st++)
		{
			int cnt=0,sum=M;
			for(int i=1;i<=n;i++)
			{
				if((st>>(i-1))&1)
				{
					cnt++;
					sum&=a[i];
				}
			}
			if(cnt>=m)
			{
				ans=max(ans,sum);
			}
		}
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
	}
	else if(n<=2000&&m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			int tmp=sum;
			for(int j=0;(1<<j)<=a[i];j++)
			{
				if(f[j]==n-1&&((a[i]>>j)&1)==0)
				{
					tmp+=(1<<j);
				}
			}
			ans=max(ans,tmp);
		}
	}
	else if(f1)
	{
		ans=M;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++)
		{
			ans&=a[i];
		}
	}
	else if(f2)
	{
		for(int i=maxj;i>=0;i--)
		{
			int x=n-(1<<maxj);
			if(x+1>=m)
			{
				int tar=1;
				for(int j=0;(1<<j)<=x;j++)
				{
					if(x/(1<<j)>=m)
					{
						tar+=x/(1<<j);
					}
				}
				ans=tar;
				break;
			}
		}
	}
	else if(maax<4)
	{
		int sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				sum1++;
			}
			else if(a[i]==2)
			{
				sum2++;
			}
			else if(a[i]==3)
			{
				sum3++;
			}
		}
		if(sum3>=m)
		{
			ans=3;
		}
		else if(sum2+sum3>=m)
		{
			ans=2;
		}
		else if(sum1+sum3>=m)
		{
			ans=1;
		}
	}
	else if(maax<1024)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=a[i];j++)
			{
				if((j&a[i])==j)
				{
					final[j]++;
				}
			}
		}
		for(int i=maax;i>=0;i--)
		{
			if(final[i]>=m)
			{
				ans=i;
				break;
			}
		}
	}
	else
	{
		ans=114514;//wozhenbuxingle woshidaqu
	}
	cout<<ans;
	return 0;
}
//qianwanbiecuoa!!!
