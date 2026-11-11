#include <bits/stdc++.h>
using namespace std;
string a;
long long n,sum = 0,k;
char l;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++)
	{
		cin >> k >> l;
		for(long long j = 1;j <= k;j++)
		{
			a += l;
		}
	}
	for(long long i = 0;i <= a.size() / 2;i++)
	{
		if(a.size() % 2 == 0 && i == a.size() / 2)
		{
			break;
		}
		if(a[i] != a[a.size() - 1 - i])
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}

