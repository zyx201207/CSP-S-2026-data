#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans,sum1,a[500005],sum[500005];
bool f;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) sum[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++)
	{
		ans=0;
		for(int j=i-1;j>=1;j--)
		{
			ans+=(i-j)*sum[i-j+1];
			if(ans>m)
			{
				f=1;
				break;
			}
//			cout<<ans<<endl;
		}
		if(f==1) break;
		else sum1=i;
//		cout<<endl;
	}
	cout<<sum1;
	return 0;
}