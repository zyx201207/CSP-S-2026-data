#include <iostream>
using namespace std;
int main()
{
	int a;
	long long b[200005];
	string c[200005];
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		cin >> b[i] >> c[i];
	}
	int sum = 0;
	string d[200005];
	long long f = 0;
	for (int j = 1; j <= a; j++)
	{
		for (int n = 1; n <= b[j]; n++)
		{
			f++;
			d[f] = c[a];
		}
	}
	for (int z = 0; z < a; z++)
	{
		if (z + 1 == f - z || z + 1 > f - z)
		{
			break;
		}
		if (d[z + 1] != d[f - z])
		sum ++;
	}
	cout << sum;
	return 0;
}