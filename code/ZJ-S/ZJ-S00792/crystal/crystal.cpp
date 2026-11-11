#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans,sum;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=1;
	ans=1;
	while(r+1<=n)
	{
		r++;
		sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m)
		{
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}