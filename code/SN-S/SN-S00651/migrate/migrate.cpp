#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[10000];
bool check(int x)
{
	if(x>m)
	{
		return 3;
	}
	else if(x==m)return 2;
	return 3;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll maxx=-1;
	for(ll i=(1<<22);i>=1;)
	{
		if(check(i)==3)
		{
			i>>=1;
		}
		else if(check(i)==2)cout<<i;
		else
		{
			i<<=1;
		}
	}
}

