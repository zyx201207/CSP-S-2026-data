//and
#include <bits/stdc++.h>
using namespace std;


int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10000],maxa = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxa = max(maxa,a[i]);
	}
	if (m == 1) cout << maxa;
	else if(m == 2) {
		maxa  = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = i+1; j <= n; j++)
			{
				int c = (a[i] & a[j]);
				maxa = max(maxa,c);
			}
		}

		cout << maxa ;
	}
	else {
		sort(a+1,a+n+1);
		maxa = a[n-m+1];
		cout << maxa;
	}
	return 0;
}
