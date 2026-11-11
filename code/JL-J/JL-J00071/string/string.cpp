#include <bits/stdc++.h>
using namespace std;
long long a[200005], n, t = 0, len = 0;
bool flag = 1;
char l[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n; i++)
	{
		cin >> a[i] >> l[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int x1, y1;
		string x2, y2;
		if(flag) {x1 = a[i] + t; y1 = a[n - i + 1];}
		else {y1 = a[n - i + 1] + t; x1 = a[i];}
		x2 = l[i], y2 = l[n - i + 1];
		if(x2 != y2)
		{
			len += min(x1, y1);
			if(x1 == y1) {t = 0;continue;}
			else if(x1 > y1 && a[i] != a[n - i]) 
			{t = x1 - y1; flag = 1; l[n - i + 1] = l[i];continue;}
			else if(x1 < y1 && a[i + 1] != a[n - i + 1])
			{t = y1 - x1; flag = 0;l[i] = l[n - i + 1];continue;}
			else
				t = 0;
		}
	}
	cout << len;
	return 0;
}
