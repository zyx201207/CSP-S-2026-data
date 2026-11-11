#include<bits/stdc++.h>
//__xiaoY
//Privet ghbdtn
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll a[200005],sum[200005],ans;
char c[200005];
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	int l=s.size();
	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i-1]) ++ans;
	}
	cout<<ans;
	return 0;
}
/*ll halflen=sum[n]/2;
	int halfpos=upper_bound(sum+1,sum+n+1,halflen)-sum-1;
	if(sum[halfpos]==halflen)
	{
		ll ls=0,rs=0,rp=n;
		for(int i=1;i<=halfpos;i++)
		{
			ls+=a[i];
			while(rp>halfpos and rs<ls)
			{
				rs+=a[rp];
				if(c[i]!=c[rp]) ans+=a[rp];
				--rp;
			}
			if(rs>ls)
			{
				++rp;
				a[rp]=rs-ls;
				if(c[i]!=c[rp]) ans-=a[rp];
			}
		}
	}
	else
	{
		ll lres=halflen-sum[halfpos],rres=(sum[n]-sum[halfpos]+1)-halflen;
		ll ls=0,rs=0,rp=n;
		for(int i=1;i<=halfpos;i++)
		{
			ls+=a[i];
			while(rp>halfpos+1 and rs<ls)
			{
				rs+=a[rp];
				if(c[i]!=c[rp]) ans+=a[rp];
				--rp;
			}
			if(rs>ls)
			{
				++rp;
				a[rp]=rs-ls;
				if(c[i]!=c[rp]) ans-=a[rp];
			}
		}
		if(rres>lres and ) ans+=labs(rres-lres);
	}
	cout<<ans;
 */ 
