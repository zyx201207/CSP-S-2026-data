#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[6000005];
int ans=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n/2;i++) 
	{
		ans=ans+abs(a[i]);
	}
	cout<<ans;
	return 0;
}                          
