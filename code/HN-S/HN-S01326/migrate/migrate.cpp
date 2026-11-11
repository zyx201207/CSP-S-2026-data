#include<bits/stdc++.h>
using namespace std;
long long int c,t,n,d,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;	
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(x[2]-x[1]>d)
		{
			cout<<0<<endl;
			continue;
		}
		cout<<n-3<<endl;
	}
	return 0;
}

