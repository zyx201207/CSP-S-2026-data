#include <iostream>
#include <utility>
using namespace std;
const int MAXN = 2e5 + 10;
pair <int, char> a[MAXN];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "r", stdout);
	int n;
	long unsigned int len = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		long unsigned int l;
		char ai;
		cin >> l >> ai;
		len += l;
		a[i].first = l;
		a[i].second = ai;
	}
	long unsigned int pl = 0, j = 0;
	for(int i = 1; i <= n; i++)
	{
		pl += a[i].first;
		if((len % 2 == 0 and pl >= len / 2) or (len % 2 == 1 and pl > len / 2))
		{
			j = i;
			break;
		}
	}
	long unsigned int ans = 0;
	int l = 1, r = n;
	while(l < j and r > j)
	{
		if(a[l].first >= a[r].first)
		{
			if(a[l].second != a[r].second)ans += a[r].first;
			a[l].first -= a[r].first;
			l--;
		}
		else
		{
			if(a[l].second != a[r].second)ans += a[l].first;
			a[r].first -= a[l].first;
			r++;
		}
		l++;
		r--;
	}
	while(l < j)
		{
			if(a[l].second != a[j].second)ans += a[l].first;
			l++;
		}
	while(r > j)
		{
			if(a[r].second != a[j].second)ans += a[r].first;
			r--;
		}
	cout << ans;
	return 0;
}
