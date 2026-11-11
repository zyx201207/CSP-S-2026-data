#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =5e5+7;
ll ans=1,n,m,now,last=1;
ll a[N];
int main(void)
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		now=max(ll(0),now);
		now+=(a[i]-a[i-1])*(i-last);
		while(now==m&&a[i+1]!=a[i])
		{
			ans=max(ans,i-last+1);
			now-=(a[i]-a[i-1])+(a[last+1]-a[last]);
			last++;
		}
		while(now>m)
		{
			ans=max(ans,i-last);
			now-=(a[i]-a[i-1])+(a[last+1]-a[last]);
			last++;
		}
	}
	ans=max(ans,n-last+1);
	cout<<ans;
	return 0;
}
