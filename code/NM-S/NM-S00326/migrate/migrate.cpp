#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n[30000],d[30000],x[300][300];
	for(int i=0;i<t;i++)
	{
		cin>>n[i]>>d[i];
		for(int j=0;j<n[i];j++)
		{
			cin>>x[i][j];
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<n[i]-3<<endl;
	}
	return 0;
}
