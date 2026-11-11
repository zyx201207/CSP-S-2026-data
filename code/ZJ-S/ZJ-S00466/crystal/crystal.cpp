#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005]={},b[500005]={},ans[500005]={};
int n=0;
ll m=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	ans[1]=1;
	ll res=m;
	for(int i=2;i<=n;i++)
	{
		ll pos=i-ans[i-1],k=0;
		ans[i]=ans[i-1]+1;
		res-=(a[i]-a[i-1])*ans[i-1];
		while(res<0)
		{
				res+=(a[i]-a[pos]);
				k++;
				pos++;
		}
		ans[i]-=k;
	}
	sort(ans+1,ans+1+n);
	cout<<ans[n];
	return 0;
} 
