#include<bits/stdc++.h>
using namespace std;
long long a[550001],n,m;
long long que[550001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long i,l=1,r=0,res=0,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		res=res+(r-l+1)*(a[i]-a[r]);
		while(res>m && l<=r)
		{
			res-=a[i]-a[l];
			l++;
		}
		++r;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}