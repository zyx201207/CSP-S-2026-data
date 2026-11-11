#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,ans;
struct Node
{
	ll x,p,pre;
}a[N];
bool cmp(Node A,Node B)
{
	return A.x<B.x;
}
bool check(ll len)
{
	ll res=0;
	for(int i=1;i<len;i++)
	{
		res+=a[len].pre-a[i].pre;
	}
	if(res<=m)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		ll len=0;
		while(a[i].x==a[i-1].x)
		{
			len++,i++;
		}
		ans=max(ans,len+1);
	}
	for(int i=1;i<=n;i++)
	{
		a[i].p=a[i].x-a[i-1].x;
	}
	for(int i=1;i<=n;i++)
	{
		a[i].pre=a[i-1].pre+a[i].p;
	}
	ll l=1,r=n+n-1;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	ans=max(ans,l-1);
	cout<<ans<<'\n';
	return 0;
}
