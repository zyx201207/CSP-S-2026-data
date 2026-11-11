#include <bits/stdc++.h>
using namespace std;
int n,a[200005],m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	cout<<(a[1]&a[2]);
	return 0;
}
