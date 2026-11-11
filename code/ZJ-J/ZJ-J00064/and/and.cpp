#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,m;
ll a[N],sum[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(i==1) sum[i]=a[i];
		else sum[i]=sum[i-1]&a[i];
	}
	sort(a+1,a+1+n);
	if(m==1) cout<<a[n];
	else if(m==n) cout<<sum[n];
	else if(n<=2000 && m==2)
	{
		ll maxt=-1;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++){
				maxt=max(maxt,(a[i] & a[j]) );
			}
		}
		cout<<maxt;
	}
	else if(sum[n]==a[1]) cout<<a[n-m+1];
	else
	{
		ll ans;
		for(int i=n;i>=n-m+1;i--)
		{
			if(i==n) ans=a[i];
			else ans=ans&a[i];
		}
		cout<<ans;
	}
	return 0;
}
