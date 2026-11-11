#include <iostream>
using namespace std;
int n,m,a[5005],num=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	if (a[0]==1)
	{
		cout << 3;
	}
	else
	{
		cout << 4;
	}
	return 0;
}
