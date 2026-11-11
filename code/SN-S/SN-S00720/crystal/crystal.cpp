#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll maxn=0;
ll a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll r=n,v=0;
	for(ll i=n;i>=1;i--)
	{
		v=v-(i-r+1)*(a[i+1]-a[i]);
		while(r>0)
        {
			if(v+a[i]-a[r]<=m)
			{
				v=v+a[i]-a[r];
				r--;
			}
			else
			{
				break;
			}
		}
		maxn=max(maxn,i-r+1);	
	}
	cout<<maxn;
	return 0;
}
