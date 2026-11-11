#include <bits/stdc++.h>
using namespace std;
int n,a[500005],ans;
long long m,sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		while(a[i]*(i-j+1)-(sum[i]-sum[j-1])>m) j++;
		ans=max(ans,i-j+1);
	}
	cout << ans;
}
