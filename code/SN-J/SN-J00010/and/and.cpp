#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	int n,m,x,maxn = -1;string s1,s;
	cin >> n >>m;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		s1 = string(a[i] % 2);
		for (int i = s1.length() - 1; i >= 0;i --)
		{
			s[i] = s1[i];
		}
		cout << s << endl;
	}
	return 0;
	
}
