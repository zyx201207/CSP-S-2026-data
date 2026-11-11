#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long i,n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long h=1;
	while(1)
	{
		int z=(a[h+1]-a[h]);
		if(m>=z*h)
		{
			m=m-z*h;
			h++;
		}
		else
		{
			break;
		}
		if(h==n)
		{
			break;
		}
	}
	cout<<h;
	return 0;
}
