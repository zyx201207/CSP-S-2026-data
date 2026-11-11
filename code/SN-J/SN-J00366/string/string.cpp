#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200001],sum;
char s[200001];
ll minn(ll x,ll y)
{
	if(x>y) return y;
	else return x;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	ll fr=1,ta=n;
	while(fr<=ta)
	{
		if(s[fr]!=s[ta])
		{
			sum+=minn(a[fr],a[ta]);
		}
	    a[fr]-=minn(a[fr],a[ta]);
	    a[ta]-=minn(a[fr],a[ta]);
		if(a[fr]==0) fr++;
		if(a[ta]==0) ta--;
	}
	cout<<sum;
	return 0;
}
