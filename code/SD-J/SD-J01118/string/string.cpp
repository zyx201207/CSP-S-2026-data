#include <bits/stdc++.h>
using namespace std;
struct p{
	long long x;
	char c;
}a[1000000];
string s;
int sum;
long long m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].x >> a[i].c;
		m += a[i].x;
		for (int j = 1;j <= a[i].x;j++)
		{
			s += a[i].c;
		}
	}
	for (int i = 0,j = m-1;i <= m/2-1;i++,j--)
	{
		if (s[i] != s[j])
		{
			sum++;
		}
	}
	cout << sum;
	cerr << sum;
	return 0;
}
