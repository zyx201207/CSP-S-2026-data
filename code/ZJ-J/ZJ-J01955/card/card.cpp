#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[1000001];
queue<ll> q;
queue<ll> qq;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		q.push(x);
		a[i]=x;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}