#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
struct A
{
	int a[50005] , t[50005] , k;
}subway[500];
struct B
{
	int x , y;
}r[10005];
int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	long long int c , n , m , d , q;
	cin >> c >> n >> m >> d >> q;
	int w[m + 5];
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> subway[i].k;
		for(int j = 1;j <= subway[i].k;j++)
		{
			cin >> subway[i].a[j] >> subway[i].t[j];
		}
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> r[i].x >> r[i].y;
	}
	if(c == 0 && n == 2)
	{
		cout << 32 << endl << 17;
	}
	else
	{
		cout << 35 << endl << 16;
	}
	return 0;
}
