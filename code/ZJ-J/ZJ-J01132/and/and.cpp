#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=2e5+10;
ll n,m,as,t=1e12,a[N];
bool sxt,sxt2,sxt3;
ll s[]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575,2097151,4194303,8388607,16777215,33554431,67108863,134217727,268435455,536870911,1073741823};
//ll s[]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
ll find(ll x)
{
	ll l=0,r=30;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(s[mid]<x) l=mid+1;
		else if(s[mid]>x) r=mid-1;
		else return mid;
	}
	return -1;
}

void dfs(ll x,ll step,ll point)
{
	if(point<as) return;
	if(x==n)
	{
		as=max(as,point);
		return;
	}
	dfs(x+1,step+1,point&a[x]);
	dfs(x+1,step,point);
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
		if(find(a[i])==-1) sxt=1;
		if(a[i]!=i-1) sxt2=1;
		if(a[i]>4) sxt3=1;
	}
	ll f=find(n);
	if(sxt==0)
	{
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		cout<<a[m];
		return 0;
	}
	else if(f!=-1&&sxt2==0)
	{
		cout<<s[f-m+1];
		return 0;
	}
	else if(m==1)
	{
		ll ans=0;
		for(ll i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	else if(m==2)
	{
		ll ans=0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m==n)
	{
		ll ans=a[1];
		for(ll i=2;i<=n;i++) ans=ans&a[2];
		cout<<ans;
		return 0;
	}
	else if(sxt3==0) 
	{
		int js[50];
		memset(js,0,sizeof(js));
		for(ll i=1;i<=n;i++) js[a[i]]++;
		cout<<js[1]<<' '<<js[2]<<' '<<js[3]<<' '<<js[4]<<'\n';
		if(js[4]>=m) cout<<4;
		else if(js[3]>=m) cout<<3;
		else if(js[3]+js[2]>=m) cout<<2;
		else if(js[3]+js[1]>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	dfs(0,0,s[30]);
	cout<<as;
}
