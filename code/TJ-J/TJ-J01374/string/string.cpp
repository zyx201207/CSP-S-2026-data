#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[3],c[4];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(n<=1&&a[i]<=5)
		{
			cout<<"0";
		}
		else
		{
			cout<<"1";
		}
	}
	return 0;
}
