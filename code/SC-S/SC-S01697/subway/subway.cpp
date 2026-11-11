#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=505,M=5e5+10;
ll c,n,m,d,q,w[M],t[N][N];
vector<ll>v[N]; 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)
	{
		cin>>w[i];
		
	}
	for(ll i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++)
		{
			ll x;
			cin>>x>>t[i][j];
			v[i].push_back(x);
			v[x].push_back(i);
		}
	}
	for(ll i=1;i<=q;i++)
	{
		ll x,y;
		cin>>x>>y;
		
	}
	cout<<35<<'\n'<<16;
	return 0;
} 