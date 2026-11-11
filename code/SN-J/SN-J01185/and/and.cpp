#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll a[N];
ll n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll ans=a[n];
	for(int i=n;i>=1;i--)
	{
		ans&=a[i];
		if(i==(n-m+1))
		{
			cout<<ans;
			return 0;
		}
	}
}
