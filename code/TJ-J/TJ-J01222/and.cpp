#include <iostream>
using namespace std;

int n,m,c;
int a[10005];
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = n;i >= n - m;i--)
	{
		c = (a[i] && a[i - 1]);
	}
	cout << c;
	return 0;
}
