#include<bits/stdc++.h>
using namespace std;
struct s
{
	int ai;
	char ci;
};
s a[200010];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, ans = 0, l, r, al, ar;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].ai >> a[i].ci;
	}
	l = 0; r = n-1; al = a[l].ai; ar = a[r].ai;
	while(l < r)
	{
		if(a[l].ci != a[r].ci)
		{
			if(al < ar)
			{
				ans += al;
			}
			else
			{
				ans += ar;
			}
		}
		if(al < ar)
		{
			ar -= al;
			l++;
			al = a[l].ai;
		}
		else
		{
			al -= ar;
			r--;
			ar = a[r].ai;
		}
	}
	cout << ans;
	return 0;
}
