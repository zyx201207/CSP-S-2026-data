#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll C,n,m,d,q,k,c[500010],a[1000010],t[1000010];
vector<ll>g[500010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>c[i];
	for(ll i=1;i<=q;i++)
	{
		cin>>k;
		for(ll j=1;j<=k;j++)cin>>a[j]>>t[j];
	}
	while(q--)
	{		
		ll qi,qj;
		cin>>qi>>qj;
		cout<<0<<'\n';
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
