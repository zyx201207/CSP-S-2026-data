#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef const int cint;
cint N=5e5+10;
ll n,m;
ll a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=0;
	ll j=1;
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-j);
		while(sum>m)
		{
			sum-=(a[i]-a[j]);
			j++;
		}
		ans=max(ans,(i-j+1));
//		cout<<i<<" "<<j<<endl;
	}
	cout<<ans;
	return 0;
}



