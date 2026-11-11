#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e6;
long long a[maxn],n,m,c;
long long sum=0,b=0;
bool cmp(long long x,long long y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1,cmp);
	for(long long i=n;i>1;i--)
	{
		if(a[i]-a[1]<=m)
		{
			sum++;
			b=i;
			c=a[i]-a[1];
			break;
		}
	}
	if(b!=0)
	{
		for(long long i=2;i<=b;i++)
		{
			if(a[b]-a[i]<=m-c)
			{
				sum++;
				c-=(a[b]-a[i]);
			}
			else if(c=0)
			{
				break;
			}
		}
		cout<<sum;
	}
	else if(b=0)
	{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}