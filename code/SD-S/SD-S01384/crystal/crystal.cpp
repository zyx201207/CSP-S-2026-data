#include<bits/stdc++.h>
//thinked by 14:28
//done by 14:39
using namespace std;
#define ll long long
ll read()
{
	ll x=0,flag=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')flag=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*flag;
}
const int N = 5e5+5;
ll a[N];
ll n,m;
ll sum[N];
bool check(ll l,ll r)
{
	if((r-l+1)*a[r]-(sum[r]-sum[l-1])<=m)return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int st=clock();
	ll ans=0;
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		ll l=1,r=i,res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i))res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<endl;
	int ed=clock();
//	cerr<<ed-st<<"ms"<<endl;
	return 0;
}
