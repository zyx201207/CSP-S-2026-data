#include<bits/stdc++.h>
#define ll long long
using namespace std;

constexpr int N = 5e5+5;

int n;
ll m;
ll a[N];
ll val=0;
int cnt=1;
int mx=-1;
int pos=1;

inline void solve()
{
	cin >> n >> m;
	for(int i=1;i<=n;++i)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i)
	{
		val+=cnt*(a[i]-a[i-1]);
		cnt++;
		if(val<=m)
		{
			mx=max(mx,cnt);
		}
		else
		{
			while(val>m)
			{
				val-=a[i]-a[pos];
				pos++;
				cnt--;
			}
		}
	}
	cout << mx << "\n";
	return ;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	solve();

	return 0;
}

