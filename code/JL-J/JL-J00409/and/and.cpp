#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll x[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a,b,maxs=-1;
	cin>>a>>b;
	for(ll i=0;i<a;i++)
	{
		cin>>x[i];
	}
	for(ll i=0,k=0;i<a;i++)
	{
		for(ll j=0;j<b;j++)
		{
			x[i]&=x[k++];
		}
		if(x[i]>maxs)
		{
			maxs=x[i];
		}
	}
	cout<<maxs<<endl;
	return  0;
}
