#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		long long y=a[2]-a[1];
		cout<<n-y-2<<endl;
	}
	return 0;
}
