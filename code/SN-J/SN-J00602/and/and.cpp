#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int minn = 100000;
	int n,m;
	cin	>> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] < minn)
		{
			minn = a[i];
		}
	}
	cout << minn;
	
}
