#include<bits/stdc++.h>
using namespace std;
long long n,m,x,Max;
bool a[200005][31];
long long check(long long ans)
{
	bool f[30];
	long long k=-1,cnt=0;
	memset(f,0,sizeof(f));
	while(ans)
	{
		k++;
		f[k]=ans%2;
		ans/=2;
	}
	for(long long i=1;i<=n;i++)
	{
		bool flag=1;
		for(long long j=0;j<=k;j++)
		{
			if(f[j]==1 && a[i][j]==0)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			cnt++;
		}
		if(cnt>=m)
		{
			break;
		}
	}
	return cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>x;
		Max=max(x,Max);
		long long k=-1;
		while(x)
		{
			k++;
			a[i][k]=x%2;
			x/=2;
		}
	}
	if(n==m) 
	{
		long long ans=0,sum=1;
		for(int i=0;i<=30;i++)
		{
			bool flag=1;
			if(i!=0)
			{
				sum*=2;
			}
			for(int j=1;j<=n;j++)
			{
				if(a[j][i]==0)
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				ans+=sum;
			}
		}
		cout<<ans;
	}
	else if(m==1)
	{
		cout<<Max;
	}
	else if(m==2)
	{
		long long M=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					long long sum=1,ans=0;
					for(int k=0;k<=29;k++)
					{
						if(k!=0) sum*=2;
						if(a[i][k]==1 && a[i][k]==a[j][k])
						{
							ans+=sum;
						}
					}
					M=max(M,ans);
				}
			}
		}
		cout<<M;
	}
	else
	{
		for(long long i=Max;i>=0;i--)
		{
			if(check(i)>=m)
			{
				cout<<i;
				break;
			}
		}
	}
	return 0;
}