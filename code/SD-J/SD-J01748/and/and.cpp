#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a[200005],vis[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long ans=2147483647;
	for(int i=n;i>=n-m+1;i--)
	{
		ans=ans&a[i];
	}
	cout<<ans<<endl;
	return 0;
}
