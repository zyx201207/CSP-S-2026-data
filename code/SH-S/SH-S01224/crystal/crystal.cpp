#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int s[500005],a[500005];
bool check(int x,int mid)
{
	if((x-mid+1)*a[x]-(s[x]-s[mid-1])<=m)return 1;
	else return 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int sum=0;
	for(int i = 1;i <= n;i++)
	{
		int l=1,r=i;
		int ans;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(i,mid))
			{
				ans=i-mid+1;
				r=mid-1;
			} 
			else l=mid+1;
		}
		sum=max(sum,ans);
	}
	cout<<sum;
	return 0;
} 
