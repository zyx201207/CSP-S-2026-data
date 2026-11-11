#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[2000005],ans=0;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while (t--)
	{
		ans=0;
		cin>>n>>d;
        vector<int> g(n);
        for (int i=0;i<=n;i++) g[i]=0;
		int p=d+d-1;
		cin>>x[1];
		for (int i=2;i<=n;i++)
		{
			cin>>x[i];
			g[x[i]-x[1]]=1;
		}
		g[0]=1;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (p==x[j]-x[i] && g[x[i]+d-1]>=1 && g[x[i]+d]>=1)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
