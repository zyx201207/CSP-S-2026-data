#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum = 0;
	cin >> n,m;
	for(int i = 0;i <= m;i++)
	{
		cin >> n >>m;
		sum++;
	}
	
	cout << sum;
	return 0;
}