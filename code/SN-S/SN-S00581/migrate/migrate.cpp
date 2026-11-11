#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int e=1;e<=t;e++)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int m=d/(a[2]-a[1]);
		
		cout<<n-2*m+1;
	}
	return 0;
}
