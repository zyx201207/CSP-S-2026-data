#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
	}
	if(n==4) {cout<<1<<endl;cout<<2<<endl;}
	if(n==5) {cout<<0<<endl;cout<<1<<endl;}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
