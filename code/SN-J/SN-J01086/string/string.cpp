#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	string a[n + 5];
	long long x[n + 5];
	bool z = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> x[i];
		string q;
		cin >> q;
		for (int j = 1;j <= x[i];j++)
		{
			a[j] = q;
		}
    }
	long long sum = 0;
	long long num = 0;
	for (int i = 1;i <= n;i++)
	{
		sum += x[i];
	}
	if (sum % 2 == 0)
	{
		long long w = 0;
		for (long long i = sum / 2;i >= 1;i--)
		{
			if (a[i] != a[i + (w * 2 + 1)])
			{
				num++;
			}
			w++;
		}
	}
	else if (sum % 2 == 1)
	{
		long long w = 0;
		for (long long i = (sum - 1) / 2;i >= 1;i--)
		{
			if (a[i] != a[i + (w * 2 + 2)])
			{
				num++;
			}
			w++;
		}
	}
	if (num == 0)
	{
		cout << 0;
		return 0;
	}
	cout << num;
	return 0; 
 } 
