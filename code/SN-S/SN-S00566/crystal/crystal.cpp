#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int sum[500005];
bool check(int l,int r)
{
	int tot=a[r]*(r-l+1);
	int s=sum[r]-sum[l-1];
	return (tot-s<=m);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	//i~R 以合成水晶，枚举 i 去二分 R 
	for(int i=1;i<=n;i++)
	{
		int R=i+1; 
		int l=i,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(i,mid))
			{
				R=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		ans=max(ans,R-i+1); 
	}
	cout<<ans;
	return 0;
}

