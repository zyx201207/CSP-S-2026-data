#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1,l=1;
long long a[500005],sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int r=2;r<=n;r++)
	{
		sum+=(a[r]-a[r-1])*(r-l);
		while(l<r&&sum>m)
		{
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
