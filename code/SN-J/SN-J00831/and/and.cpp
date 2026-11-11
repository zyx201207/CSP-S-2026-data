//张庭煊 SN-J00831 西安市益新中学
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n , m;
	cin >> n >> m;
	int a[100005];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]-a[i+1]>3||a[i]-a[i+1]<3)
		{
			sum = a[i];
		}
	}
	cout << sum;
	return 0;
}
