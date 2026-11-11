#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005],s[200005],ans,l,sta[200005],sto[200005],all[500005],b[500005],top,cnt;
unordered_map<ll,char>mp;
char c[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
//	clog<<n<<endl;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
		sta[++top]=s[i-1]+1;
		sto[top]=s[i];
	}
	l=s[n];
//	clog<<l<<endl;
	if(l%2==1)
	{
		ll pos=(l+1)/2;
//		clog<<pos<<' '<<top<<endl;
		for(ll i=1;i<=top&&sta[i]<=pos;i++)
		{
			all[++cnt]=pos-sta[i];
		}
		for(ll i=top;i>=1&&sto[i]>=pos;i--)
		{
			all[++cnt]=sto[i]-pos;
		}
		sort(all+1,all+cnt+1,less<ll>());
//		for(ll i=1;i<=cnt;i++)clog<<i<<' '<<all[i]<<' ';
//		clog<<endl;
		for(ll i=1;i<=cnt;i++)
		{
//			clog<<pos<<' '<<all[i]<<endl;
			ll left=pos-all[i],right=pos+all[i];
			ll bl=lower_bound(s+1,s+n+1,left)-s,br=lower_bound(s+1,s+n+1,right)-s;
			if(c[bl]!=c[br])ans+=(all[i]-all[i-1]);
		}
	}
	else
	{
		ll pos=(l+1)/2;
		for(ll i=1;i<=top&&sta[i]<=pos;i++)
		{
			all[++cnt]=pos-sta[i];
		}
		for(ll i=top;i>=1&&sto[i]>=pos+1;i--)
		{
			all[++cnt]=sto[i]-pos-1;
		}
		sort(all+1,all+cnt+1,less<ll>());
//		for(int i=1;i<=n;i++)clog<<all[i]<<endl;
//		clog<<endl;
		ll bb1=lower_bound(s+1,s+n+1,pos)-s,bb2=lower_bound(s+1,s+n+1,pos+1)-s;
		if(c[bb1]!=c[bb2])ans+=1;
		for(ll i=1;i<=cnt;i++)
		{
			ll left=pos-all[i],right=pos+1+all[i];
			ll bl=lower_bound(s+1,s+n+1,left)-s,br=lower_bound(s+1,s+n+1,right)-s;
			if(c[bl]!=c[br])ans+=(all[i]-all[i-1]);
//			clog<<all[i]-all[i-1]<<endl;
		}
	}
	cout<<ans;
	return 0;
}