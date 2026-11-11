#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n[t+1],d[t+1],ans[t+1];
	for (int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		int x[n[i]+5];
		for (int j=1;j<=n[i];j++)
		{
			cin>>x[j];
		}
		ans[i]=abs(x[n[i]]-x[1])/2;
	}
	for (int i=1;i<=t;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
