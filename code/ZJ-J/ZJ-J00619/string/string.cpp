#include<bits/stdc++.h>
using namespace std;
struct ff{
	int x;
	char c;
};
ff a[200005];
long long sum[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
		sum[i]=sum[i-1]+a[i].x;
	}
	long long t=0;
	long long sum1;
	if(sum[n]%2==1)
	{
		sum1=sum[n]/2+1;
		int i=1;
		while(sum1>sum[i])
			i++;
		long long l=sum1,r=sum1,l1=i,r1=i;
		while(l!=1||r!=sum[n])
		{
			if(l-sum[l1-1]-1>sum[r1]-r)
			{
				if(a[l1].c!=a[r1].c)
					t+=(sum[r1]-r);
				l-=(sum[r1]-r+1);
				r1++;
				r=sum[r1-1]+1;
				if(a[l1].c!=a[r1].c)
					t++;
			}
			else if(l-sum[l1-1]-1<sum[r1]-r)
			{
				if(a[l1].c!=a[r1].c)
					t+=(l-sum[l1-1]-1);
				r+=(l-sum[l1-1]);
				l1--;
				l=sum[l1];
				if(a[l1].c!=a[r1].c)
					t++;
			}
			else if(l-sum[l1-1]-1==sum[r1]-r)
			{
				if(a[l1].c!=a[r1].c)
					t+=(sum[r1]-r);
				if(l1==1&&r1==n)
					break;
				l1--;
				r1++;
				l=sum[l1];
				r=sum[r1-1]+1;
				if(a[l1].c!=a[r1].c)
					t++;
			}
		} 
	}
	if(sum[n]%2==0)
	{
		sum1=sum[n]/2;
		int i=1;
		while(sum1>sum[i])
			i++;
		long long l1=i,r1=i;
		if(sum[i]==sum1)
			r1++;
		long long l=sum1,r=sum1+1;
		if(a[l1].c!=a[r1].c)
			t++;
		while(l>=1||r<=sum[n])
		{
			if(l-sum[l1-1]-1>sum[r1]-r)
			{
				if(a[l1].c!=a[r1].c)
					t+=(sum[r1]-r);
				l-=(sum[r1]-r+1);
				r1++;
				r=sum[r1-1]+1;
				if(a[l1].c!=a[r1].c)
					t++;
			}
			else if(l-sum[l1-1]-1<sum[r1]-r)
			{
				if(a[l1].c!=a[r1].c)
					t+=(l-sum[l1-1]-1);
				r+=(l-sum[l1-1]);
				l1--;
				l=sum[l1];
				if(a[l1].c!=a[r1].c)
					t++;
			}
			else if(l-sum[l1-1]-1==sum[r1]-r)
			{
				if(a[l1].c!=a[r1].c)
					t+=(sum[r1]-r);
				if(l1==1&&r1==n)
					break;
				l1--;
				r1++;
				l=sum[l1];
				r=sum[r1-1]+1;
				if(a[l1].c!=a[r1].c)
					t++;
			};
		} 
	}
	cout<<t;
	return 0;
}
