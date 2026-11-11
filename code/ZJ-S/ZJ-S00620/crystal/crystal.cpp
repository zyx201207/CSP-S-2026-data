#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N],s[N];
long long m;
bool check(int l,int r)
{
	long long sum = s[r] - s[l - 1];
	long long ad = a[r] * (r - l + 1ll) - sum;
	return ad <= m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i ++)
	{
		s[i] = s[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		int l = 1,r = i;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(!check(mid,i))
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}
		ans = max(ans,i - l + 1);
	}
	cout << ans << '\n';
	return 0;
}
