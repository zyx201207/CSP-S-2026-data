#include<bits/stdc++.h>
using namespace std;
long long c,t,a[5000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
		int n,d;
		cin>>n>>d;
		if(n<=3 || d%2==1)
		{
			cout<<0;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				if(a[j]-a[i]>d)
				{
					if(a[j]-a[i]<2*d)
					{
						ans++;
					}
					else break;
				}
			}
		}
		cout<<ans<<endl;
    }
    
    return 0;
}
