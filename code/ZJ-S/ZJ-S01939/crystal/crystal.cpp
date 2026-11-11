#include<bits/stdc++.h>
using namespace std;
const int N(5e5+5);
int n,ans;
long long m,a[N],q[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i(1);i <= n;++i) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i(1);i <= n;++i)
	{
		q[i] = q[i-1]+a[i];
		int l(1),r(i);
		while(l < r)
		{
			int mid(l+r>>1);
			if(a[i]*(i-mid+1)-(q[i]-q[mid-1]) <= m)
			{
				r = mid;
			}
			else
			{
				l = mid+1;
			}
		}
		ans = max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
