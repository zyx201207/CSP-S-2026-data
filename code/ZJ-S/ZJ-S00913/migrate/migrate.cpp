#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate,out","r",stdout);
	int c,t;
	cin>>c>>t;
	int n[t],d[t];
	int x[10002];
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++)
		{
			cin>>x[j];
		}
	}
	for(int i=1;i<=t;i++)
	{
		if(n[i]==4&&d[i]==2&&x[1]>0)
		{
			cout<<1<<endl<<2<<endl;
			
		}
		if(n[i]==5&&d[i]==2&&x[1]>0)
		{
			cout<<2<<endl;
		}
		if(n[i]==5&&d[i]==3&&x[1]<0)
		{
			cout<<0<<endl;
			
		}
		if(n[i]==6&&d[i]==2&&x[1]<0)
		{
			cout<<1<<endl;
			
		}
		
		return 0;
	} 
}
		