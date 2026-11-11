#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
	ll a,k0,k1;
};
ll n,m,a[200005],last;
node s[200005];
node sq(ll a)
{
	ll k0=0,k1=0,b=a;
	while(b)
	{
		if(b%2==0)k0++;
		else k1++;
		b/=2;
	}
	node x;
	x.a=a;
	x.k0=k0;
	x.k1=k1;
	return x;
}
bool cmp(node x,node y)
{
	if(x.k0!=y.k0)return x.k0<y.k0;
	return x.k1>y.k1;
}
bool cnp(ll x,ll y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=sq(a[i]);
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		for(ll i=1;i<n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				last=max(last,a[j]&a[i]);
			}
		}
		cout<<last;
		return 0;
	}
	sort(s+1,s+n+1,cmp);
	last=s[1].a;
	for(ll i=2;i<=m;i++)
	{
		last&=s[i].a;
	}
	cout<<last;
	return 0;
}
