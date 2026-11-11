#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int a[N],m,n;
int sum[N];
int solve(int id,int x)
{
	int l=1,r=id,ans=id;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(m+sum[id]-sum[mid-1]>=(id-mid+1)*x)
		{
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
	int res=0;
	for(int i=n;i>=1;i--)
	{
		int t=solve(i,a[i]);
		res=max(res,i-t+1);
	}
	cout<<res;
	return 0;
}
