#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
long long c[500005];
long long n,m;
long long _special(int flag1,int flag2)
{
	long long i,j;
	long long ans=0;
	if(flag1)
	{
		if(n%2==0)
		{
			int t=n>>1,f=1;
			for(i=t,j=t+1;m>=0;)
			{
				if(f)
				{
					m-=(t-i);
					if(m<0||i<1)
						break;
					--i;
				}
				else
				{
					m-=(j-t);
					if(m<0||j>n)
						break;
					++j;
				}
				++ans;
				f^=1;
			}
		}
		else
		{
			int t=n>>1|1,f=1;
			++ans;
			for(i=t-1,j=t+1;m>=0;)
			{
				if(f)
				{
					m-=(t-i);
					if(m<0||i<1)
						break;
					--i;
				}
				else
				{
					m-=(j-t);
					if(m<0||j>n)
						break;
					++j;
				}
				++ans;
				f^=1;
			}
		}
	}
	else if(flag2)
	{
		if(n%2==0)
		{
			int t=n>>1,f=1;
			for(i=t,j=t+1;m>=0;)
			{
				if(f)
				{
					m-=(arr[t]-arr[i]);
					if(m<0||i<1)
						break;
					--i;
				}
				else
				{
					m-=(arr[j]-arr[t]);
					if(m<0||j>n)
						break;
					++j;
				}
				++ans;
				f^=1;
			}
		}
		else
		{
			int t=n>>1|1,f=1;
			++ans;
			for(i=t-1,j=t+1;m>=0;)
			{
				if(f)
				{
					m-=(arr[t]-arr[i]);
					if(m<0||i<1)
						break;
					--i;
				}
				else
				{
					m-=(arr[j]-arr[t]);
					if(m<0||j>n)
						break;
					++j;
				}
				++ans;
				f^=1;
			}
		}
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int flag1=1,flag2=1,flag3,ans=0;
	long long i,j,k;
	scanf("%lld %lld",&n,&m);
	arr[0]=0;
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&arr[i]);
		if(flag1&&arr[i]!=i)
			flag1=0;
		else if(flag2&&i>2&&arr[i]-arr[i-1]!=arr[i-1]-arr[i-2])
			flag2=0;
		if(i!=1&&arr[i-1]>arr[i])
			flag3=0; 
		if(flag1==0&&flag2==0)
			break;
	}
	k=i;
	if(flag1||flag2)
	{
		printf("%lld",_special(flag1,flag2));
	}
	else
	{
		for(j=k+1;j<=n;++j)
		{
			scanf("%d",&arr[j]);
		}
		int s;
		long long sum;
		for(i=1;i<=n;++i)
		{
			sum=s=0;
			for(j=1;j<=n;++j)
			{
				c[j]=abs(arr[i]-arr[j]);
			}
			sort(c+1,c+n+1);
			for(j=1;j<=n;++j)
			{
				sum+=c[j];
				if(sum>m)
					break;
				++s;
			}
			ans=max(ans,s);
		}
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
