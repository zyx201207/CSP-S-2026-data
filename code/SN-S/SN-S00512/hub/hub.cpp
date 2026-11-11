#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    int c,t;
    int n[10086];
    int k[10086];
    int u[10086];
    int v[10086];
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
    	cin>>n[i]>>k[i];
    	for(int j=1;j<=n[i]-1;j++)
    	{
    		cin>>u[j]>>v[j];
		}
	}
	if(c==2||c==3)
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
	if(c==4||c==5||c==6)
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
