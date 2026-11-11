#include<bits/stdc++.h>
using namespace std;
int a[50010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long d,n;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(d%2==0)
		{
			cout<<max(n-d-1,0ll)<<endl;
		}
		else
		{
			cout<<max(n-d-2,0ll)<<endl;
		}
		
	}
	return 0;
}
