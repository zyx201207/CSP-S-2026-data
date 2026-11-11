#include<bits/stdc++.h>
using namespace std;
int n,m,mx;
struct node
{
	int val,popcount;
	bool operator < (const node &other) const
	{
		if(popcount == other.popcount) return val > other.val;
		return popcount > other.popcount;
	}
}a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].val;
		a[i].popcount = __builtin_popcount(a[i].val);
		mx = max(mx,a[i].val);
	}
	if(m == 1) cout << mx;
	else if(m == 2)
	{
		int ans = 0;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) ans = max(ans,a[i].val & a[j].val);
		cout << ans;
	}
	else if(m == n)
	{
		int ans = 2147483647;
		for(int i = 1;i <= n;i++) ans &= a[i].val;
		cout << ans;
	}
	else
	{
		sort(a + 1,a + n + 1);
		int ans = 2147483647;
		for(int i = 1;i <= m;i++) ans &= a[i].val;
		cout << ans;
	}
	return 0;
}
