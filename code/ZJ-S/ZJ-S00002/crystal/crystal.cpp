#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int sum[N];
int pre[N];
int nums=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int l=1;
	for(int r=1;r<=n;r++)
	{
		if(a[r]*(r-l+1)-sum[r]+sum[l-1]<=m)
		{
			;
		}
		else
		{
			while(a[r]*(r-l+1)-sum[r]+sum[l-1]>m&&l<=r)
			{
				l++;
				nums=max(nums,r-l+1);
			}
		}
		nums=max(nums,r-l+1);
	}
	cout<<nums;
	return 0; 
}
