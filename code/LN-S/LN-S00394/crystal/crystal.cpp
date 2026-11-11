#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long s[500010];
long long sum[500010];
bool flagA=1,flagB;
//long long c[500010];//gaojingdu

int main()
{
	 freopen("crystal.in","r",stdin);
	 freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=a[i]-a[i-1];
		//if(i!=1 and s[i]!=1)flagA=0;
		if(s[i]!=s[i-1] and i!=1)flagB=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+s[i];
	}
	if(flagB)
	{
		long long t=1;
		for(int i=1;i<n;i++)
		{
			if(i*(i*s[2]+s[2])/2>m)
			{
				break;
			}
			else t++;
		}
		t=min(t,n);
		cout<<t;
		return 0;
	}
/*	for(int i=1;i<=n;i++)
	{
		c[i]=c[i-1]+sum[i];
	}
	
	
	long long k=1;
	long long maxx=1;
	for(int i=2;i<=n;i++)
	{
		if((c[i]-c[k]-(k*sum[k]))>m)
		{
			for(int j=k;j<=i;j++)
			{
				k++;
				if((c[i]-c[k]-(k*sum[k]))<=m)break;
			}
		
		}
			maxx=max(maxx,i-k+1);
	}
	*/
	
	
  //  50scores or more
	int maxx=1;
	for(int i=2;i<=n;i++)
	{
		long long total=0;
	    int all=1;
		for(int j=i-1;j>=1;j--)
		{
			total+=sum[i]-sum[j];

			if(total>m)
			{
				break;
			}
			else 
			{
				all++;
			}
		}
		maxx=max(maxx,all);
	}
	cout<<maxx;
	return 0;
}
