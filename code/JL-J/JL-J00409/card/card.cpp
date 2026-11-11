#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll x[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	sort(x,x+n);
	for(int i=0;i<n;i++)
	{
		cout<<x[i]<<' ';
	}

	return  0;
}
