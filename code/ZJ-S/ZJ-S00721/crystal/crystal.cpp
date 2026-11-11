#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,a[500005],dp[500005],ans;

int main()
{
	//freopen("crystal3.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[1]=1;
	for(ll i=n;i>1;i--)
	{
		ll m2=m;
		ll num=1;
		for(int j=i-1;j>0;j--)
		{
			ll x=abs(a[i]-a[j]);
			if(m2>=x)
			{
				num++;
				m2-=x;
			}
			else
			{
				break;
			}
			if(m2<0)
			{
				break;
			}
		}
		ans=max(ans,num);
		if(ans>=i)
		break;
	}
	cout<<ans;
//	fclose(stdin);
	//fclose(stdout);
	return 0;
}
