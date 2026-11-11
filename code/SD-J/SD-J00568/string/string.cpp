#include <bits/stdc++.h>
using namespace std;
const int N=5e5 + 5;
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
long long a[N];
char c[N];
int n;
long long ans;
int main()
{

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		//cout << a[i] <<' ' << c[i] << endl;
	}
	int i = 1;
	int j = n;
	while(i <= j)
	{
		if (c[i] != c[j])
		{
			ans = ans + min(a[i],a[j]);
		
		}
		if (a[i] >= a[j])
		{
				a[i] -= a[j];
				j--;
		}
		else
		{
			a[j] -= a[i];
			i++;
		}
//		cout << i << ' ' << j << ' ' << ans1 << ' ' << ans2 << endl;
//		cout << "--------------------------------------------" << endl;
	}
	cout << ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/


