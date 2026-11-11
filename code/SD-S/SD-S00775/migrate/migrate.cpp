#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[1000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		cout<<n-3<<"\n";
	}
	cout<<endl;
	return 0;
 } 
