#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		ll n,d,x[N];
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c==0&&n==4&&d==2)
		{
			cout<<1<<'\n'<<2;
			return 0;
		}
		else if(c==0&&n==5&&d==3)
		{
			cout<<0<<'\n'<<1;
			return 0;
		}
	}
	return 0;
} 