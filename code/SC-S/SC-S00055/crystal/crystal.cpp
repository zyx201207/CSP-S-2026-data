#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll a[N],c;
map<ll,ll> mp;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m,l=0,r=-1e12;
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		l=min(l,a[i]);
		r=max(r,a[i]);
		if(a[i]!=i) f=0; 
	}
	if(f)
	{
		int i=1;
		while(1)
		{
			m-=i;
			if(m<0) break;
			i++;
		}
		cout<<i;
		return 0;
	}
	sort(a+1,a+n+1);
	ll s=0;
	for(int i=l;i<=r;i++) s=max(s,mp[i]);
	for(int i=r;i>=l;i--)
	{
		if(mp[i]==s)
		{
			c=i;
			break;
		} 
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==c)
		{
			int x=1;
			for(int j=i;j>=1;j--)
			{
				m-=(c-a[j]);
				if(m<0) break;
				x++;
			}
			ans=max(ans,x);
		}
	}
	cout<<ans;
	return 0;
} 