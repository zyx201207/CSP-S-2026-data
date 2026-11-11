#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	int n;
	cin >> n;
	vector <long long> a(n, 0);
	vector <char> c(n, ' ');
	long long len = 0;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a[i] = t;
		len += t;
		char let;
		cin >> let;
		c[i] = let;
	}
//	cout << len << endl;
	long long cnt = 0;
	int head = 0, tail = n - 1, alreadyhead = a[0], alreadytail = a[n - 1];
	for (long long i = 0; i < len / 2; )
	{
//		if (i == alreadyhead)
//		{
////			cout << "1" << endl;
//			head++;
//			alreadyhead += a[head];
//		}
//		if (i == alreadytail)
//		{
//			tail--;
//			alreadytail += a[tail];
////			cout << "2" << endl;
//		}
		long long j = i;
		if (c[head] != c[tail])
		{
//			cout << c[head] << " " << c[tail] << endl;
			i += min(a[head], a[tail]);
			if (i > len / 2)
			{
				cnt += len / 2 - j - 1;
			}
			cnt += min(a[head], a[tail]);
			if (a[head] < a[tail])
			{
				a[tail] -= a[head];
				head++;
			}
			else if (a[head] > a[tail])
			{
				a[head] -= a[tail];
				tail--;
			}
			else
			{
				head++;
				tail--;
			}
//			cout << i << endl;
		}
		else
		{
			i += min(a[head], a[tail]);
			if (a[head] < a[tail])
			{
				a[tail] -= a[head];
				head++;
			}
			else if (a[head] > a[tail])
			{
				a[head] -= a[tail];
				tail--;
			}
			else
			{
				head++;
				tail--;
			}
		}
	}
	cout << cnt;
	return 0;
}
/*
seat27
*/
