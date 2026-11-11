#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				if(x[j]-x[i]>d) ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
