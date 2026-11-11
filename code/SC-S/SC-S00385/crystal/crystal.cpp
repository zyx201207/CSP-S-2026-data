#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500100],da;
long long x;
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
		int x=m,h=0;
		for(int j=i;j>=1;j--)
		{
			x=x-(a[i]-a[j]);
			if(x<0)
			{
				break;
			}
			h++;
		}
		if(da<h)
		{
			da=h;
		}
	}
	cout<<da;
	return 0;
}