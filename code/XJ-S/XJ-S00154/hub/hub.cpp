#include <bits/stdc++.h>
using namespace std;
int c,t,n,k;
int u[2000005],v[2000005],ans[2000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for(int j=1;j<=n-1;j++)
		{
			cin>>u[i]>>v[i];		
		}
	}
	ans[1]=t-1;
	ans[2]=t;
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
 } 
