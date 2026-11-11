#include <bits/stdc++.h>
using namespace std;
long long c,T,n,d,x[2000005],gc,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while (T--)
	{
		cin>>n>>d;
		ans=0;
		for (int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		gc=d/(x[2]-x[1]);
		if (gc<=1)
			ans=0;
		else
			ans=max(ans,n-(gc*2-1));
		cout<<ans<<"\n";
	}
	return 0;
}
