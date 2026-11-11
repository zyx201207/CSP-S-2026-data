#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int N=2e5+10;
long long a[N];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,num=0;
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<=n-1;i++)
		scanf("%lld",&a[i]);
	
	//m=1
	if(m==1)
	{
		long long maxn=0;
		for(int i=0;i<=n-1;i++)
			maxn=max(maxn,a[i]);
		printf("%lld",maxn);
		return 0;
	}
	
	//m=n
	if(m==n)
	{
		long long num=a[0];
		for(int i=1;i<=n-1;i++)
			num=num&a[i];
		printf("%lld",num);
		return 0;
	}
	
	//m=2
	if(m==2)
	{
		long long maxn=0;
		for(int i=0;i<=n-1;i++)
			for(int j=i+1;j<=n-1;j++)
				maxn=max(maxn,a[i]&a[j]);
		printf("%lld",maxn);
		return 0;
	}
	
	//m=n-1
	if(m==n-1)
	{
		long long maxn=0,maxx=0,num=a[0];
		for(int i=0;i<=n-1;i++)
		{
			int maxy=0;
			int bj=a[i];
			while(bj!=0)
			{
				if(bj%2==0)
					maxy++;
				bj/=2;
			}
			if(maxy>maxn)
			{
				maxn=maxy;
				maxx=i;
			}
		}
		for(int i=1;i<=n-1;i++)
			if(i!=maxx)
				num=num&a[i];
		printf("%lld",num);
		return 0;
	}
	
	//A
	int bz=0;
	for(int i=0;i<=n-1;i++)
	{
		int bj=a[i]+1;
		while(bj!=0)
		{
			if(bj%2==1)
				bz=1;
			bj/=2;
		}
		if(bz==1)
			break;
	}
	if(bz==0)
	{
		long long num;
		sort(a,a+n,cmp);
		num=a[0];
		for(int i=1;i<=m-1;i++)
			num=num&a[i];
		printf("%lld",num);
		return 0;
	}
	
	//B
	int bj=0;
	for(int i=1;i<=n-1;i++)
		if(a[i]!=a[i-1]+1)
			bj=1;
	long long nn=n;
	if(bj==0)
		while(nn!=0)
		{
			if(nn%2==1)
				bj==1;
			nn/=2;
		}
	if(bj==0)
	{
		int num=0;
		int nnn=n;
		long long ans=0;
		while(nnn!=0)
		{
			nnn/=2;
			num++;
		}
		nnn=n/2;
		if(m>nnn)
		{
			printf("0");
			return 0;
		}
		num--;
		while(nnn!=0)
		{
			ans++; 
			nnn/=2;
			if(m>nnn)
			{
				for(int i=0;i<=num-1;i++)
					ans=ans*2;
				printf("%lld",ans); 
				return 0;
			}
			num--;
		}
	}
	
	long long numm;
	sort(a,a+n,cmp);
	numm=a[0];
	for(int i=1;i<=m-1;i++)
		numm=numm&a[i];
	printf("%lld",numm);
	return 0;
}
