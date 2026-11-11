#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
long long num;
char b[1000005], c[1000005], L;
int main()
{
	freopen("string.in","w",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >>a[i];
		cin >> b[i];
		c[i] = a[i] * b[i];
		L += c[i];
	}
	if (n % 2 == 0)
	{
		num = n - 1;
	}
	num = n - 1;
	printf("%lld",num);
	return 0;
}
