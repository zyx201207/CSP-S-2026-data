#include <bits/stdc++.h>
using namespace std;
long long a[200005], ans;
char c[200005], c2[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	int n;
	cin >> n;
	int r = 0;//r是a的个数 
	c[0] = '-';
	while(n--)
	{
		int m;
		char s;
		cin >> m >> s;
		if (s == c[r]) a[r] += m;
		else
		{
			r++;
			c[r] = s;
			c2[r] = s;
			a[r] = m;
		}
	}
	if (r == 1)
	{
		cout << "0";
		return 0;
	}
	/*for (int i = 1; i <= r; i++) cout << c[i] << " ";
	cout << "\n";
	for (int i = 1; i <= r; i++) cout << a[i] << " ";*/
	//cout << r << " " << ceil(r / 2) << "\n";
	for (int i = r; i >= ceil(r / 2); i--) 
	{
		int k = abs(a[i] - a[r - i + 1]);
		if (i == r - i) 
		{
			if (r % 2 == 1)
			{
				ans += c2[i] - c[i];
				break;
			}
			else 
			{
				ans += abs(a[i + 1] - a[i]);
				break;
			}
		}
		if (c[i] == c[r - i + 1] && a[i] == a[r - i + 1])
		{
			continue;
			cout << "c = c, a = a\n";
		}
		else if (c[i] != c[r - i + 1] && a[i] == a[r - i + 1])
		{
			ans += a[i];
			cout << "c != c, a = a\n";
		}
		else if (c[i] != c[r - i + 1] && a[i] != a[r - i + 1])
		{
			ans += min(a[i], a[r - i + 1]);
			//cout << a[i] << " " << a[r - i + 1] << " " << i << " " << r - i;
			if (a[i] > a[r - i + 1]) a[r - i] -= k;
			else a[i + 1] -= k;
			cout << "c != c, a != a\n";
		}
		else if (c[i] == c[r - i + 1] && a[i] != a[r - i + 1])
		{
			ans += k;
			if (a[i] > a[r - i + 1]) a[r - i] -= k;
			else a[i + 1] -= k;
			cout << "c = c, a != a\n";
		}
		//cout << ans << " " << k << endl;
	}
	cout << ans;
	return 0;
 } 
