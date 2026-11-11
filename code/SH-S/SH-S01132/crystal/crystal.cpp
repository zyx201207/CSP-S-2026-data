#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int maxn=5e5+100;
int n;
int ans=0;
ll m;
ll a[maxn];
ll arr[maxn];//qianzhuihe
bool check(int x,int flag)
{
	ll sum=arr[flag]-arr[x-1];
	if((flag-x+1)*a[flag]-sum>m)
	    return false;
	return true;
}
int solve(int k)
{
	if(k==1)
	    return 1;
	int l=1,r=k;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid,k)==true)
		    r=mid;
		else
		    l=mid+1;
	}
	return (k-r+1);
}
signed main()
{
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	arr[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		arr[i]=arr[i-1]+a[i];
	}
	for(int k=1;k<=n;k++)
	{
		int tt=solve(k);
		if(tt>ans)
		{
			ans=tt;
//			cout<<k<<" ";
		}
	}
	cout<<ans<<endl;
	return 0; 
}
