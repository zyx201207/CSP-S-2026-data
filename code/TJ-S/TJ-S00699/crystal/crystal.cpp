#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long t=0LL;
	for(int l=1,r=1;(r<=n);r++)
	{
		while(l<r and t>m)
		{
			t-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
		t+=(a[r+1]-a[r])*(r-l+1);
	}
	cout<<ans;
	return 0;
}
