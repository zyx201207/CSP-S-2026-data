#include<bits/stdc++.h>
using namespace std;
long long a[500015];
long long b[500015];
long long js(long long p,long long q)
{
	if (q==1)
	{
		return b[p];
	}
	else
	{
		return js(p-1,q-1)+q*b[p];
	}
}
int main()
{
	freopen("crystal.in",r,"stdin");
	freopen("crystal.out",w,"stdout");
	long long n,m;
	cin>>n>>m;
	for (long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for (long long i=0;i<n-1;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	long long ans=0;
	for (long long i=1;i<n;i++)
	{
		bool f=0;
		for (long long j=i-1;j>=0;j--)
		{
			if (f==0)
			{
				long long s=js(i-1,i-j);
				if (s==m)
				{
					//cout<<js(i-1,i-j)<<" "<<i<<" "<<j<<" "<<endl;
					ans=max(ans,i-j+1);
					f=1;
				}
				else if (s>m)
				{
					//cout<<js(i-1,i-j)<<" "<<i<<" "<<j<<" "<<endl;
					ans=max(ans,i-j);
					f=1;
				}
			}
		}
	}
	cout<<ans;
}