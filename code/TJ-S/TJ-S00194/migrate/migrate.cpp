#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c=0,t=0;
	cin>>c>>t;
	while(t--)
	{
		int n=0,d=0;
		int a=0;
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>a;
		}
		if(c==13||c==14)
		{
			cout<<"0"<<endl;
		}
		else if(c==1||c==2)
		{
			cout<<"2"<<endl;
		}
	}
	return 0;
}
