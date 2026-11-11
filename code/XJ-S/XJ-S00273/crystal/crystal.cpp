#include<bits/stdc++.h>
using namespace std;
long long int m,ans,MAX,x;
int n,f;
long long int a[500005],g[500005],k[500005];
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
		g[i]=a[i]+g[i-1];
		k[i]=a[i]-a[i-1];
		if(k[i]!=k[i-1]&&i>2) f=1;
	}
	if(f==0)
	{
		x=floor(sqrt((m/k[2])*2));
		cout<<x;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int l=1;
		int r=i;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(((i-mid+1)*a[i]-g[i]+g[mid-1])>m)
			{
				l=mid+1;
			}
			else
			{
				r=mid;
			}
		}
		if(i-l+1>MAX)
		{
			MAX=i-l+1;
		}
	}
	cout<<MAX;
	return 0;	
} 
