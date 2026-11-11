#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
struct node
{
	char c;
	ll cnt;
};
node a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].cnt >> a[i].c;
	}
	ll ans = 0;
	ll l = 1,r = n;
	ll lcnt = a[1].cnt,rcnt = a[n].cnt; 
	while (l <= r)
	{
//		cout << l << " " << r << endl;
		if (lcnt > rcnt)
		{
			if (a[l].c != a[r].c)
			{
				ans += rcnt;
			}
			lcnt -= rcnt;
			r--;
			rcnt = a[r].cnt;
		}
		else if (lcnt < rcnt)
		{
			if (a[l].c != a[r].c)
			{
				ans += lcnt;
			}
			rcnt -= lcnt;
			l++;
			lcnt = a[l].cnt;
		}
		else
		{
			if (a[l].c != a[r].c)
			{
				ans += lcnt;
			}
			l++;
			lcnt = a[l].cnt;
			r--;
			rcnt = a[r].cnt;
		}
//		cout << ans << endl; 
	}
	cout << ans << endl;
	return 0;
}
