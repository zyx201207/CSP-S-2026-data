#include<bits/stdc++.h>
using namespace std;
int c=0,t=0,n=0,k=0,u[1000005]={0},v[1000005]={0},ans[5];
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
			cin>>u[j]>>v[j];
		}
		ans[i]=n/(k+1);
	}
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
