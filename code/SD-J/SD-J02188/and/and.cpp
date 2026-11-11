#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e9+10;
ll a[N];
int main()
{
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ll maxx=(a[i]&&a[j]);
			ans=max(ans,maxx);
		}
	}
	cout<<ans;
	return 0;
}
