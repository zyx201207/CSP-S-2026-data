#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

ll a[500005],n,m,sum=0,l=1,r,ans=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);/*
	for(ll i=2;i<=n;i++)
	{
		sum += 1LL*(a[i]-a[i-1])*(i-1);
		if(sum>m)
		{
			r = i-1;
			ans = r;
			break;
		}
	}*/
	for(int r=1;r<=n;r++)
	{
		sum += 1LL*(a[r]-a[r-1])*(r-l);
		while(sum>m && l<r)
		{
			sum-=(a[r]-a[l]);
			l++;
		}
		ans = max(ans,r-l+1);
		//cout<<r-l+1<<endl;
	}
	cout<<ans;
	return 0;
}