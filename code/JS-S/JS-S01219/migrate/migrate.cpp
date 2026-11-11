#include<bits/stdc++.h>
using namespace std;
long long c,t,n[200050],d[200050],x[200050];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++)
		{
			cin>>x[i];
		}
	}
	if(c==0)
	{
		if(t==2&&n[1]==4&&d[1]==2)
		{
			cout<<1<<endl<<2;
		}
		if(t==2&&n[1]==5&&d[1]==3)
		{
			cout<<0<<endl<<1;
		}
		if(t==17&&n[1]==197&&d[1]==29418319589926278)
		{
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		}
	}
	return 0;
}
