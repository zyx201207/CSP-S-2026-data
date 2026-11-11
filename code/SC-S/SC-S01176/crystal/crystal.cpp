#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500003];
int ii;
int now;
int last;
int ans;
unsigned int tmp;
signed main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i)cin >> a[i];
	sort(a+1,a+n+1);
	last=1;
	now=1;
	for(int i=2;i<=n;++i)
	{
		tmp+=(a[i]-a[i-1])*(i-last);
		if(tmp>m)
		{
			ans=max(ans,i-last);
			while(tmp>m)
			{
				tmp-=(a[i]-a[last]);
				++last;
			}
		}
	}
	cout << ans;
	return 0;
}