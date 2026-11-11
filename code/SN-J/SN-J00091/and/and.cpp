#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[20000];
	cin >> n >> m;
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	if(a[0]==a[1])
	{
		cout << a[0]&&a[1];
	}
	else if(a[0]-=a[1]>a[1]-a[2])
	{
		cout << a[1]&&a[2]; 
	}
	else
	{
		cout << a[2]&&a[3];
	} 
	return 0;
}
