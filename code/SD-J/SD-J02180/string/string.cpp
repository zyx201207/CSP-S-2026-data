#include <bits/stdc++.h>
#define ll long long
const int mxn=333333;
ll a[mxn];
char c[mxn];
bool has[mxn];
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) has[i]=false;
	ll len=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	ll ans=0;
	ll l=a[1],r=a[n];
	int lp=1,rp=n;
	ll hal=len/2;
	ll n1,n2;
	ll has=0;
	while(lp<rp)
	{
		ll now=min(l-has,r-has);// now bi jiao
		char c1=c[lp],c2=c[rp];
		if(c1!=c2){ ans+=now; 
	}
		has+=now;
		if(l<r)
		{
			lp++;
			l+=a[lp];
			if(l>hal)
			{
				ll tmp=l-hal;
				l-=tmp;
			}
		}
		else if(l>r)
		{
			rp--;
			r+=a[rp];
			if(r>hal)
			{
				ll tmp=r-hal;
				r-=tmp;
			}
		}
		else if(l==r)
		{
			lp++;
			rp--;
			l+=a[lp];
			r+=a[rp];
			if(l>hal)
			{
				ll tmp=l-hal;
				l-=tmp;
			}
			if(r>hal)
			{
				ll tmp=r-hal;
				r-=tmp;
			}
			if(lp>=rp) break;
		}
	}
	
	cout<<ans;
	return 0;
}
