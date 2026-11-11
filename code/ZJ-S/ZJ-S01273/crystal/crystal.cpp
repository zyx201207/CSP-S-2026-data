#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n;
long long a[N],sum,m,cnt=1,ans=0;
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
	int r=1;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		while(sum<=m&&r<=n)
		{
			ans=max(ans,cnt);
			r++;
			cnt++;
			sum+=(a[r]-a[r-1])*(cnt-1);
		}
		sum-=(a[r]-a[i]);
		cnt--;
	}
	cout<<ans;
	return 0;
}