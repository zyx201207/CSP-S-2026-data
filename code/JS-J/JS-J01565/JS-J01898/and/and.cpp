#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[222],x,sum,ans;
int main()
{

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x=a[i];
		sum=0;
		while(x!=0)
		{
			sum++;
			if(x%2!=0)
				b[sum]++;
			x/=2;		
		}
	}
	for(int i=35;i>=0;i--)
	{
		if(b[i]>=m)
		{
			sum=i;
			break;
		}
	}
	long long v=pow(2,sum);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=v)
			a[i]-=(a[i]/v)*v;
	}
	sort(a+1,a+1+n,greater<long long>());
	ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}