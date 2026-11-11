#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
const long long M=1e12;
long long n,m;
long long a[N],b[N];
long long w=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool flaga=1,flagb=1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)flaga=0;
	}
	if(flaga==0)
	{
		sort(a+1,a+1+n);
		for(long long i=2;i<=n;i++)
		{
			b[i-1]=a[i]-a[i-1];
			if(i>2&&b[i-1]!=b[i-2])flagb=0;
			w+=b[i-1]*(i-1);
		}
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	if(flaga)
	{
		long long ans=1;
		for(long long i=1;i<=n;i++)
		{
			if(m-i>=0)
			{
				m-=i;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(flagb)
	{
		long long ans=1;
		long long cnt=1;
		while(1)
		{
			if(m-b[1]*cnt>=0)
			{
				m=m-b[1]*cnt;
				ans++;
				cnt++;
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	if(w<=m)
	{
		cout<<n;
		return 0;
	}
	if(n<=5000)
	{
		long long num1=0;
		for(long long i=n-1;i>=1;i--)
		{
			long long m1=m,ans1=0;
			for(long long j=i;j>=1;j--)
			{
				if(m1-b[j]>=0)
				{
					m1-=b[j];
					ans1++;
				}
			}
			for(long long j=n-1;j>i;j--)
			{
				if(m1-b[j]>=0)
				{
					m1-=b[j];
					ans1++;
				}
			}
			if(ans1>num1)num1=ans1;
		}
		cout<<num1;
		return 0;
	}
	long long cnt,num=1,q;
	bool flag=0;
	for(long long i=1;i<n;i++)
	{
		if(b[i]==0)
		{
			num++;
			q=i;
			flag=1;
		}
	}
	long long p=1;
	while(1)
	{
		bool flagc=0;
		long long ans=M;
		for(long long i=1;i<=n;i++)
		{
			if(b[i]>0)
			{
				ans=min(ans,b[i]);
				flagc=1;
			}
			if(ans==b[i])cnt=i;
		}
		if(flag&&p==1)
		{
			cnt=q;
			p++;
		}
		if(flagc)
		{
			if(m-b[cnt]>=0)
			{
				a[cnt]+=b[cnt];
				m-=b[cnt];
				num++;
				for(long long i=1;i<n;i++)
				{
					b[i]=a[cnt]-a[i];
				}
			}
			else break;
		}
		else
		{
			for(long long i=1;i<n;i++)
			{
				if(b[i]!=0)ans=min(ans,abs(b[i]));
				if(ans=abs(b[i]))cnt=i;
			}
			for(long long i=1;i<n;i++)
			{
				b[i]=a[cnt]-a[i];
			}
		}
	}
	cout<<num;
	return 0;
 } 
