#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
int n;
int ans;
ll m,a[N],sum[N];
void read(int &s)
{
	s=0;char c=getchar();int f=1;
	for(;c<48||c>57;c=getchar()) (c=='-')&&(f=-1);
	for(;c>47&&c<58;c=getchar()) s=(s<<1)+(s<<3)+(c^48);
	s*=f;
}
void read(ll &s)
{
	s=0;char c=getchar();int f=1;
	for(;c<48||c>57;c=getchar()) (c=='-')&&(f=-1);
	for(;c>47&&c<58;c=getchar()) s=(s<<1)+(s<<3)+(c^48);
	s*=f;
}
int find(int x)
{
	int l=1,r=x,mid,ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[x]*(x-mid+1)-(sum[x]-sum[mid-1])<=m) r=mid-1,ans=mid;
		else l=mid+1;
	}
	return ans;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int t=find(i);
		ans=max(ans,i-t+1);
	}
	cout<<ans;
	return 0;
}