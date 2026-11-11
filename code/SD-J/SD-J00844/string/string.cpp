#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=0x3f3f3f3f;
ll n,l,r,ans;
struct str
{
	ll cnt;
	string s;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].cnt>>a[i].s;
	}
	while(l<r)
	{
		ll k=min(a[l].cnt,a[r].cnt);
		if(a[l].s!=a[r].s)
		{
			ans+=k;
		}
		a[l].cnt-=k;
		a[r].cnt-=k;
		if(a[l].cnt==0)
		{
			l++;
		}
		if(a[r].cnt==0)
		{
			r--;
		}
	}
	cout<<ans;
	return 0;
}
