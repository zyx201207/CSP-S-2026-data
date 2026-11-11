#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int ans,n,last,a[N],m,zong;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	stable_sort(a+1,a+1+n);
	ans=1;last=1;zong=0;
	for(int i=2;i<=n;i++)
	{
		zong+=(i-last)*(a[i]-a[i-1]);
		if(zong<=m)ans=max(ans,i-last+1);
		else
		{
			while(zong>m)
			{
				zong-=a[i]-a[last];
				last++;
			}
			ans=max(ans,i-last+1);
		}
//		cout<<i<<" "<<last<<" "<<zong<<" "<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}