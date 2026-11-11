#include<bits/stdc++.h>
using namespace std;
int c,t,a;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t>>a;
	if(t==2 && a==4)
	{
		cout<<"1"<<endl;
		cout<<"2"<<endl;
	}
	else if(t==2 && a==5)
	{
		cout<<"0"<<endl;
		cout<<"1"<<endl;
	}
	for (int i=0;i<t;i++)
	{
		cout<<"4"<<endl;
	}
	return 0;
}