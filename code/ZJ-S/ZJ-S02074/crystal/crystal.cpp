#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	ll a[n+5],cnt1=1,cnt2=0;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int k=2;k<=n;k++)
	{
		cnt1=0;
		for(int i=1;i<=k;i++)
		{
			ll sum=0;
			sum+=(a[k]-a[i]);
			if(sum<=m)
			{
				cnt1++;
			}
		}
		cnt2=max(cnt1,cnt2);
	}
	cout<<cnt2;
	return 0;
}
