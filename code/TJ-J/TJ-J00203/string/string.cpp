#include <bits/stdc++.h>
using namespace std;

long long ans;
int n, l, r;
struct stu
{
	int sum;
	char c;
}a[200010];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].sum >> a[i].c;
	}
	r = n-1;
	
	while(l < r)
	{
		if (a[l].sum == a[r].sum)
		{
			if (a[l].c != a[r].c) ans += a[l].sum;
			l++;r--;
		}
		else if (a[l].sum < a[r].sum)
		{
			if (a[l].c != a[r].c) ans += a[l].sum;
			a[r].sum -= a[l].sum;
			l++;
		}
		else if (a[l].sum > a[r].sum)
		{
			if (a[l].c != a[r].c) ans += a[r].sum;
			a[l].sum -= a[r].sum;
			r--;
		}
	}
	
	cout << ans;
	return 0;
}
