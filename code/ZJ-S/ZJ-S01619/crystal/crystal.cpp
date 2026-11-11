#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
const ll maxn=500009;
ll s[maxn],n,m;
ll pre[maxn];
int main()
{
	fre(crystal);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	pre[0]=0;
	for(ll i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+s[i];
	}
	ll l,r,mid,ans=0,cnt;
	ll t;
	for(ll i=1;i<=n;i++)
	{
		l=0;
		r=i-1;
		cnt=0;
		while(l<=r)
		{
			mid=(l+r)>>1;
			t=i-mid;
			if(pre[i]-pre[t-1]+m>=s[i]*(mid+1))
			{
				l=mid+1;
				cnt=mid;
			}	
			else
			{
				r=mid-1;
			}
		}
		ans=max(ans,cnt+1);
	}
	cout<<ans;
	return 0;
}