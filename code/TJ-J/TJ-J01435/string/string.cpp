#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long a[200001];
char c[200001];
long long ans = 0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	int x = 1,y = n;
	long long num1 = a[1],num2 = a[n];
	while(x < y)
	{
		long long k = min(num1,num2);
		if(c[x] != c[y]) ans += k;
		num1 -= k;
		num2 -= k;
		if(num1 == 0)
		{
			x++;
			num1 = a[x];
		}
		if(num2 == 0)
		{
			y--;
			num2 = a[y];
		}
	}
	cout << ans;
}
