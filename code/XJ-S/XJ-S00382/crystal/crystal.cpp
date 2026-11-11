#include<bits/stdc++.h>
using namespace std;

long long a[600005],s[600005];
long long n,m;

bool chaike(int x,int y)
{
	if (y==1)
	{
		return 1;
	}
	if (a[y]*(y-x)-(s[y-1]-s[x-1])<=m) return 1;
	else return 0;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int ma=0;
	for (int i=1;i<=n;i++)
	{
		int l=1,r=i,mid;
		while (l<=r)
		{
			mid=(l+r)/2;
			if (chaike(mid,i))
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		if (chaike(mid,i))ma=max(ma,i-mid+1);
		if (chaike(mid+1,i))ma=max(ma,i-mid);
		if (chaike(mid-1,i))ma=max(ma,i-mid+2);
	}
	cout<<ma;
	return 0;
}
