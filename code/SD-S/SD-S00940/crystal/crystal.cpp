#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3f;
ll a[510000];
ll	pre[510000];
ll n,m;
ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
bool check(int k)
{
	int l=1,r=l+k-1;
	ll sum=0;
	ll minn=INF;
	while(l+k-1<=n)
	{
		r=l+k-1;
		sum=a[r]*(k-1)-(pre[r-1]-pre[l-1]);
		minn=min(minn,sum);
	//	cout<<"l="<<l<<" "<<"r="<<r<<" ";
	//	cout<<"sum="<<sum<<" ";
	//	cout<<"minn="<<minn;
		l++;
	}
	if(minn<=m) return true;
	else return false;
}
ll ef(int l,int r)
{
	ll ans=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
	//	cout<<"mid="<<mid<<" ";
		if(check(mid))//mid¸öË®¾§ 
		{
	//		cout<<"true";
			ans=mid;
			l=mid+1; 
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	//	cout<<di[i]<<" ";
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	//cout<<"\n";
	cout<<ef(1,n)<<"\n";
	return 0; 
}
