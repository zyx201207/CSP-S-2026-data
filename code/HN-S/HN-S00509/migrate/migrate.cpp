#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=n;i>=2;i--)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(((a[i]-a[j])%d!=0)&&(a[i]-a[j]>d)) 
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
