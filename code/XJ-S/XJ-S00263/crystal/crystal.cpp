#include<iostream>
using namespace std;
int a[100005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,ans=0,cnt=0,mid;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]+i==a[i+1])
		{
			mid+1;
			ans+1;
		}
	}
	cout<<ans+mid;
	return 0;
}
