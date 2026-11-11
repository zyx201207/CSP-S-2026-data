#include <bits/stdc++.h>
using namespace std;
int main()
}
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout)
	int x,y,a[100001];
	cin >> x >> y;
	for(int i = 1;i <= x;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= x;i++)
	{
		for (int j = i+1;j <= x;j++)
		{
			if (a[j] > a[i])
			{
				int c;
				c= a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}
	}
	cout << a[y];
}
