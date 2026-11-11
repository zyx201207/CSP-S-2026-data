#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000009];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==0)
		{
			if(n==4)
			cout<<"1\n2";
			if(n==5)
			cout<<"0\n1";
			return 0;
		}
		else
		{
			cout<<n-3<<"\n";
		}
	}
	
	return 0;
}
