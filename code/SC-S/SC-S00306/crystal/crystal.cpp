#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,mx;
int a[N],sum[N],ans=1,b[N];
bool cck(int x,int k)
{
	int su=a[k]*(k-x+1);
	if(m+sum[k]-sum[x-1]>=su)return 1;
	else return 0;
}
int check(int x)
{
	int ke=n,key=-1;
	for(int i=1;i<=n;i++)
	{
		b[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x)
		{
			ke=i-1;
			break;
		}
		b[i]=b[i-1]+x-a[i];
	}
	for(int i=1;i<=ke;i++)
	{
		if(b[ke]-b[i-1]<=m)
		{
			key=i;
			break;
		}
	}
	if(key==-1)return -1;
	return (ke-key+1);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])continue;
		int l=1,r=i,mid=0;
		while(l<=r)
		{
			mid=l+(r-l)/2;
			if(cck(mid,i))r=mid-1;
			else l=mid+1;
		}
		if(cck(mid,i)&&i-mid+1>ans)
		{
			ans=i-mid+1;
			mx=i;
		}
	}
	cout<<ans;
	return 0;
}