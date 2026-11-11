#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=500005;

int n,m;
int a[N],sum[N];
int ans=1;

int cost(int l,int r)
{
	int s=sum[r]-sum[l-1];
	int tot=(r-l+1)*a[r];
	return tot-s;
}

int erfen(int x)
{
	int l=0,r=x+1;
	int ans=x;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(cost(mid,x)<=m)
		{
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	
	return x-ans+1;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	for(int i=1;i<=n;i++) ans=max(ans,erfen(i));
	
	cout<<ans<<endl;
	return 0;
}
//14.32 发现大水晶不能变成小水晶，考虑枚举最大的水晶是哪一个，二分即可 
//14.49 finish
