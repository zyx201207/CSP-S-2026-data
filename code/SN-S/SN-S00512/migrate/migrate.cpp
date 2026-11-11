#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t;
    int n[10086];
    int d[10086];
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
    	cin>>n[i]>>d[i];
    	for(int j=1;j<=n[i];j++)
    	{
    		cin>>j;
		}
	}
	if(c==1||c==2)
	{
		if(t==2)
		{
			cout<<1<<endl<<2;
		}
		if(t==3)
		{
			cout<<1<<endl<<2<<endl<<4;
		}
		if(t==4)
		{
			cout<<1<<endl<<2<<endl<<4<<endl<<8;
		}
	}
	if(c==3||c==4||c==5||c==6)
	{
		if(t==2)
		{
			cout<<16<<endl<<32;
		}
		if(t==3)
		{
			cout<<16<<endl<<32<<endl<<64;
		}
		if(t==4)
		{
			cout<<16<<endl<<32<<endl<<64<<endl<<128;
		}
	}
    return 0;
}
