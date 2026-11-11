#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+1];
	int max=0;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	if(m=1)
	{
		cout << max;
	}
	return 0;
}
