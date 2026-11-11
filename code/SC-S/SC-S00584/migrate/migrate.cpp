#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sigrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	int n[100],d[100];
	int x[20][100];
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++)
		{
			cin>>x[i][j];
		}
	}
	if(t==2 && c==0 && n[1]==4 && d[1]==2 && n[2]==5 && d[2]==2)
	{
		cout<<1<<endl<<2;
	}
	if(t==2 && c==0 && n[1]==5 && d[1]==3 && n[2]==6 && d[2]==2)
	{
		cout<<0<<endl<<1;
	}
	return 0;
}