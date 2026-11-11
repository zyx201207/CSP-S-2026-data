#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,sum=0,ans=1;
	while(l<=r&&r<=n)
	{
		if(sum<=m)
		{
			ans=max(ans,r-l+1);
			r++;
			sum+=(r-l)*(a[r]-a[r-1]);
		}
		else
		{
			sum-=a[r]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
} 