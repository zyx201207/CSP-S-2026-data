#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,i,n,k;
	cin >> a[i];
	for(i += 1;i <= n;i++)
	{
		for (n += i;n <= m;n++)
		{
		if(a[i-n] == k)
		{
			a[i-n] - k;
		
		}
		}
	}
	cout << a[i];
	return 0;
}
