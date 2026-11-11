#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005],m,sum[500005];
int n;
bool check(int mid)
{
	for(int i=mid;i<=n;i++)
	{
		if(mid*a[i]-sum[i]+sum[i-mid]<=m)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	//system("fc /w crystal.out crystal.out");
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int l=1,r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid)==1)
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l<<"\n";
	return 0;	
}
