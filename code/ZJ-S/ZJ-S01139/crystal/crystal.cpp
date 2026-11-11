#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
ll i,j,n,m,a[N],b[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		ll cnt=m,sum=a[i];
		for(j=i;j<=n;j++)
		{
			cnt-=(j-i)*(a[j]-sum);
			if(cnt<0)
			{
				ans=max(ans,j-i);
				break;
			}
			sum=a[j];
  		}
	}
	cout<<ans;
	return 0;
}
