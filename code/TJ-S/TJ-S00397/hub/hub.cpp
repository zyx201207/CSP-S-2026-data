#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,sumu=0;
	cin>>c>>t;
	int n[t+1],k[t+1],ans[t+1];
	for (int i=1;i<=t;i++)
	{
		cin>>n[i]>>k[i];
		int u[n[i]],v[n[i]];
		sumu=0;
		for (int j=1;j<=n[i]-1;j++)
		{
			cin>>u[j]>>v[j];
			sumu+=abs(u[j]-v[j])*4/5;
		}
		ans[i]=sumu/(n[i]-1);
	}
	for (int i=1;i<=t;i++)
	{
		cout<<ans[i]+1<<endl;
	}
	return 0;
}

