#include <bits/stdc++.h>
using namespace std;
const long long maxn=2e5+10;
long long n,m,pp;
long long a[maxn];
long long b[maxn];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++)
		cin >> a[i];
	if(m==n)
	{
		long long ans=0;
		for(long long i=1;i<n;i++)
			ans=max(ans,a[i]&a[i+1]);
		cout<<ans;
	}
	else if(m==1)
	{
		long long ans=0;
		for(long long i=1;i<=n;i++)
			ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==2)
	{
		long long ans=0;
		for(long long i=1;i<=n;i++)
			for(long long j=i+1;j<=n;j++)
					ans=max(ans,a[i]&a[j]);
		cout<<ans;
	}
	else
	{
		long long a1=-1;
		long long h=1;
		int op=1;
		while(op!=m+1)
		{
			a1=-1;
			for(pp=1;pp<=n;pp++)
				a1=max(a1,a[pp]);
			b[h]=a1;
			h++;
			for(int i=1;i<=n;i++)
				if(a[i]==a1)
				{
					a[i]=0;
					break; 
				}
			op++;
		}
	 	long long ppp=0;
	 	h--;
		for(int i=1;i<=h;i++)
		{
			if(i==1)
				ppp=b[i]&b[i+1];
			else
				ppp=ppp&b[i];
		}	
		cout<<ppp;
	}
	return 0;
} 
