#include<bits/stdc++.h>
using namespace std;
int t,c;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n;
		long long d;
		cin>>n>>d;
		bool flag=true;
		for(int i = 1;i <= n;i++)
		{
			cin>>a[i];
			if(a[i]==0)flag=false;
		}
		if(flag)cout<<1;
		else cout<<0;
	}
	return 0;
}
