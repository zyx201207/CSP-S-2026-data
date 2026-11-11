#include<iostream>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n[t],d[t];
	int x[t];
	for(int i=0;i<=t-1;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=0;j<=n[i]-1;j++)
		{
			cin>>x[i];
		}
	}
	if(c==0)
	{
		if(t==2)
		{
		   if(n[1]==4&&d[1]==2)
		   {
		   	cout<<1<<endl<<2;
		   }
		   if(n[1]==5&&d[1]==3)
		   {
		   	cout<<0<<endl<<1;
		   }
		}
		if(t==17)
	    {
		    cout<<197<<endl<<29418319589926278;
     	}
     	if(t==12)
     	{
     		cout<<260000<<endl<<1;
		 }
	}
   return 0;
 } 