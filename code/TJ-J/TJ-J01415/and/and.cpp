#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin >> n;
	int a[n],max=0,m=0;
	for (int i=1;i<=n;i++)
	{
		cin >> a[n];
		if(a[n]>max)
		{
			m=max;
			max=a[n];
	
		}
	}
	cout << m;
	return 0;
}
