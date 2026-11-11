#include<bits/stdc++.h>
using namespace std;
long long a[500050];
char c[500050];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long sum=0;
	long long x=1,y=n;
	while(!(x>=y))
	{
		if(c[x]==c[y])
		{
			if(a[x]>a[y])
			{
				a[x]-=a[y];
				if(a[x]<=0)
				{
					x++;
				}
				y--;
			}
			else
			{
				a[y]-=a[x];
				if(a[y]<=0)
				{
					y--;
				}
				x++;
			}
		}
		else
		{
			if(a[x]>a[y])
			{
				a[x]-=a[y];
				sum+=a[y];
				if(a[x]<=0)
				{
					x++;
				}
				y--;
			}
			else
			{
				a[y]-=a[x];
				sum+=a[x];
				if(a[y]<=0)
				{
					y--;
				}
				x++;
			}
		}
	}
	cout<<sum;
	return 0;
}

