#include <bits/stdc++.h>
using namespace std;
int a[200003];
int n;
char c[200003];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	if(n == 1)
		cout << 0;
	if(n == 2)
	{
		if(c[1] != c[2])
			cout << min(a[1],a[2]);
	}
	return 0;
}