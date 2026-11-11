#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[200005];
int main()
{
	freopen("and.in",r,stdin);
	freopen("and.out",w,stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		b[i] = a[i] & a[i + 1];
	}
	return 0;
}
