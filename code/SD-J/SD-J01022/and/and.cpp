#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=2e5+5;
ll a[N];
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ll ans=a[1];
	ll cnt=1;
	for(int i=2;i<=m;i++)
	{
		ans&=a[i];

	}
	cout<<ans;
	return 0;
} 
