#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=5e5+10;
int n,m;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int now=0;
	int lst=1;
	int lstans=0;
	int sum=0;
	int ans=1;
	for(int i=2;i<=n;++i)
	{
		int dt=a[i]-a[i-1];
		sum+=dt;
		now+=(i-lst)*dt;
		while(now>m&&lst<=i)
		{
			now-=sum;
			lst++;
			sum-=a[lst]-a[lst-1];
		}
		ans=max(ans,i-lst+1);
	}
	cout<<ans;
	return 0;
}
/*
Oct31==Dec25?
*/
