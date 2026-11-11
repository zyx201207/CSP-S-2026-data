#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N],ans=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int v=1;v<=t;v++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		cout<<ans; 
	}
	return 0;
 } 
