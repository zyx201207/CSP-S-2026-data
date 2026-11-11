#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+5;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) 
		{
			ans++;
			continue;
		}
		if(m-(i-1)*(a[i]-a[i-1])>=0)
		{
			a[i-1]=a[i];
			m-=(i-1)*(a[i]-a[i-1]);
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
