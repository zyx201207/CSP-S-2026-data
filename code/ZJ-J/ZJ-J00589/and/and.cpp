#include<bits/stdc++.h>
using namespace std;
long long n,m,k[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
	}
	sort(k+1,k+n+1);
	long long ans=k[n];
	for (int i=n-1;i>=n-m+1;i--)
	{
		ans=ans&k[i];
	}
	cout<<ans;
	
	return 0;
}
