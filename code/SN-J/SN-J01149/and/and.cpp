#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long big=-1;
	long long a[100005]; 
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	cout<<(a[1]&a[2]&a[3]);
	return 0;
} 
