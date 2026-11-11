#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int p=1,ans=0,x=0;
	for(int i=1;i<=n;i++)
	{
		x+=(a[i]-a[i-1])*(i-p);
		while(x>m)x-=a[i]-a[p++];
		ans=max(ans,i-p+1);
	}
	printf("%lld",ans);
}
