#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,a[10001];
	int sum,sum1= 0;
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i <= m;i++)
	{
		sum = a[i] & a[i+i];
		if(sum >= sum1)
		{
			sum1 = sum;
		}
	}
	cout << sum1;
	return 0;
}
