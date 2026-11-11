#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		int x;
		cin >> x;
		a[i] = x;
	}
	sort(a,a + n + 1);
	cout << a[m];
 } 
