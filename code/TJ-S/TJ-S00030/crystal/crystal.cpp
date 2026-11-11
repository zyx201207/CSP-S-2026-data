#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int b[500005];
map<int,int> mp;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];		
	}
	sort(a+1,a+n+1);
	int cnt=0;
	int p=0;
	int ans1=0;
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		cnt+=(a[i]-a[i-1])*(i-p-1);
		if(cnt>m)
		{
			ans1=max(ans1,ans);
			p++;
			cnt-=a[i]-a[p];
		}
		else ans++;
	}
	cout << ans1;


	return 0;
}


