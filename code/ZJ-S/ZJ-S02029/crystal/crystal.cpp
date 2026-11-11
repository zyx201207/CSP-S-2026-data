#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],b[500005],c[500005],k,i,pri,l,r;
bool check(ll k)
{
	pri=1e18+1;
	for(ll i=1;i<=n-k+1;i++)
	{
		pri=min(pri,c[i]-c[i+k-1]-(k-1)*b[i+k-1]);
	}
	return pri<=m;
}
ll burst()
{
	ll l,r,mid;
	l=1;
	r=n;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return r;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=n;i>=1;i--)
	{
		b[i]=a[n]-a[i];
		c[i]=b[i]+c[i+1];
	}
	cout<<burst();
	return 0;
}
/*

5 5
 1  2  4  8  9
 8  7  5  1  0
 21 13 6  1  0
     -2c
 a  2 -b

5 8
-3 -1  2  2  7
 0 

10 0
2 4 6 8 10 12 14 16 18 20
6 4 2 0

13 0
1 1 4 5 1 4 1 9 1 9 8 1 0

*/