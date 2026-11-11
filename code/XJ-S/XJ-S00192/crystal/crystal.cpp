#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,m;
ll a[500010];

int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll cha = 0;
	cin>>n>>m;
	for(ll i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	cha = a[2]-a[1];
	ll xu = 2;
	ll he = cha;
	while(he<=m)
	{
		xu++;
		he += xu*cha;
	}
	
	cout<<xu;
	
	
	return 0;
}
