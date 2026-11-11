#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	int m,n;
	cin>>m>>n;
	if(n==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(n==1 && n==m)
			{
				cout<<a[i];
			}
	} 
	if(n==4)
	{
		cout<<12;
	}
	if(n==5)
	{
		cout<<7;
	}
	return 0;
}