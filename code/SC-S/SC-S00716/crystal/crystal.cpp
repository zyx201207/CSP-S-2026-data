#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;long long a[N],m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);long long k=0;int ans=1;
	for(int i=1,l=1;i<=n;i++)
	{
		k+=(a[i]-a[i-1])*(i-l);
		while(k>m)k-=(a[i]-a[l++]);
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}