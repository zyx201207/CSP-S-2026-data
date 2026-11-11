#include<bits/stdc++.h>
using namespace std;
int n, m,num = 0,sum = 0;
long long a[200005];
int main()
{
	freopen("and.in","w",stdin);
	freopen("and.out","w",stdout);
	cin >>n >>m;
	for (int i = 0;i < n;i++)
	{
		cin >>a[i];
	}
	for (int i = 0;i < n;i++)
	{
		sum= a[i]&a[i+1];
		num = max(sum,num);
	}
	cout << num;
	return 0;
}
