#include <iostream>
#include <algorithm>
using namespace std;
//
int a[500000];
int n;
long long m;
int aa = 0;
//
int main()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	//
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	//
	sort (a, a+n);
	for (int i = n - 1; i >= 0; --i)
	{
		int num = 0, count = 0;
		for (int j = i; num <= m && j >= 0; --j)
		{
			num += a[i] - a[j];
			count++;
			if (num > m)
			{
				count--;
			}
		}
		//cout << endl;
		//cout << count << endl << endl;
		if (count > aa)
		{
			aa = count;
		}
	}
	cout << aa;
	//
	return 0;
}