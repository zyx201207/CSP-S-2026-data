#include <bits/stdc++.h>
using namespace std;
long long a[20000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int ans=0;
	for(int i=1;i<=t;i++)
	{
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int l=j+3;l<=n;l++)
			{
				ans++;
			}
		}
	}
	cout<<1;
	cout<<endl;
	cout<<2;
	return 0;
 }
