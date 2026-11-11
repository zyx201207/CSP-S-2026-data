#include <bits/stdc++.h>
using namespace std;
const int N = 100000005;
int a[N];
int c[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n , m;
	cin >> n >> m;
	for(int i =1; i <= n;i++)
	{
		cin >> a[i];
		c[i] = a[i] - a[i-1];
	}
	long long ans = 0;
	cout << n << ' ' << m << endl;
	for(int i = 1; i <= n;i++)
	{
		//cout << c[i] << ' ';
		ans += c[i];
	}
	cout << ans;
	return 0;
}
