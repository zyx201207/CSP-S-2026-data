#include<bits/stdc++.h>
using namespace std;
int a[35];
int b[35];
int c[200005];
int cnt=0;
int cnt1=0;
long long sum=0;
int andd(int n,int m)
{
	sum=0;
	cnt=0;
	cnt1=0;
	while(n>=1)
	{
		cnt++;
		a[cnt]=n%2;
		n/=2;
	}
	while(m>=1)
	{
		cnt1++;
		b[cnt1]=m%2;
		m/=2;
	}
	
	for(int i=min(cnt,cnt1);i>=1;i--)
	{
		if(a[i]==b[i]&&a[i]==1)
		{
			sum+=pow(2,i-1);
		}

 	}
 	return sum;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==2)
	{
		for(int i=2;i<=n;i++)
		{
			maxn=max(maxn,andd(c[i-1],c[i]));
		}
		cout<<maxn;
	}
	if(m==n)
	{
		int last=0;
		int zui=0;
		for(int i=3;i<=n;i++)
		{
			int last=andd(c[i-2],c[i-1]);
			zui=andd(last,c[i]);
		}
		cout<<zui;
	}
	if(m==n-1)
	{
		int last=0;
		int zui=0;
		int zui1=0;
		for(int i=3;i<=n-1;i++)
		{
			int last=andd(c[i-2],c[i-1]);
			zui=andd(last,c[i]);
		}
		for(int i=4;i<=n;i++)
		{
			int last=andd(c[i-2],c[i-1]);
			zui1=andd(last,c[i]);
		}
		cout<<max(zui,zui1);
	}
	return 0;
 }
