#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[100000005];
/*int zh(int b)
{
	string c;
	while(b!=0)
	{
		c=b%2+c;
		b/=2;
	}
	return c;
}*/
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (maxx<a[i])
		{
			maxx=a[i];
		}
		//cout<<zh(a[i])<<" ";
	}
	cout<<maxx;
	return 0;
}