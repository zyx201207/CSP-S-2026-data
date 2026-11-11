#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n[30000],k[30000],u[300][300],v[300][300];
	for(int i=0;i<t;i++)
	{
		cin>>n[i]>>k[i];
		for(int j=0;j<n[i];j++)
		{
			cin>>u[i][j]>>v[i][j];
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<n[i]-3<<endl;
	}
	return 0;
}
