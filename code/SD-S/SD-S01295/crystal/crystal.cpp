#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+9;
ll n,m;
ll a[N];
bool check(ll x)
{
//	cout<<n<<" ";
	for(int i=1;i <= n-x+1;i++)
	{
		ll sum=0;
		for(int j=i;j <= i+x-1;j++)
		{
			sum+=a[i+x-1]-a[j];
		}
//		cout<<sum<<" ";
		if(sum<=m)
		{
			return true;
		}
//		cout<<1;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int vis1=0;
	int vis2=0;
	for(int i=1;i <= n;i++) 
	{
		cin >> a[i];
		if(a[i]!=i)
		{
			vis1=1;
		}
		else if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>2)
		{
			vis2=1;
		}
	}
	if(n>5000&&vis1==0||n>5000&&vis2==0)
	{
		ll ans=0;
		for(int i=n;i >= 1;i--)
		{
			if(a[n]-a[i]<=m)
			{
				ans++;
				m-=(a[n]-a[i]);
			}
		}
		cout<<ans;
		return 0;
	}
	ll l=1,r=n;
	sort(a+1,a+n+1);
	while(l<=r)
	{
		ll mid=(l+r)/2;
//		cout<<mid<<"\n";
		if(check(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
//		cout<<"\n";
	}
	cout<<r;
	return 0;
}

