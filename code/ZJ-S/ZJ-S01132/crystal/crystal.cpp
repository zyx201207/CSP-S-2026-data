#include <bits/stdc++.h>
#define N 500010
#define int long long
using namespace std;
int n,m;
int a[N];
int sum;
int ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int p=1;
	for(int i=1;i<=n;i++)
	{
		sum+=(i-p)*(a[i]-a[i-1]);
		while(sum>m) sum-=a[i]-a[p],p++;
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}
