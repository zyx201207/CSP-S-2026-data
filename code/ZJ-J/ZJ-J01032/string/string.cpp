#include <bits/stdc++.h>
using namespace std;

long long n;
long long sum;
char a[100005];
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		long long b;
		char c;
		cin >> b >> c;
		for(long long j = sum;j <= sum + b;j++)
		{
			a[j] = c;
		}
		sum += b;
	}
	int d = 0;
	for(long long i = 1;i <= sum/2+1;i++)
	{
		if (a[i] != a[sum-i])
		{
			d++;	
		}
	}
	cout << d;
	return 0;
	
}