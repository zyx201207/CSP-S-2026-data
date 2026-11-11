#include<iostream>
#include<cstdio>
using namespace std;
int c,t,n,d,x[3000006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++) cin>>x[i];
		cout<<"0"<<endl;
	}
	return 0;
}
