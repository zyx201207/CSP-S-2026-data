#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,l=1,cnt=1,z=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		z+=cnt*(a[i]-a[i-1]);
		cnt++;
		while(z>m)
		{
			z-=(a[i]-a[l]);
			l++;
			cnt--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 