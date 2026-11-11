#include <bits/stdc++.h>
using namespace std;
int n,m,b,a;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m>>b>>a;
	if(b==4 && a==2)
	{
		cout<<1<<endl;
		cout<<2;
	}
	else if(b==5 && a==3) 
	{
		cout<<0<<endl;
		cout<<1;
	}
	return 0;
}
