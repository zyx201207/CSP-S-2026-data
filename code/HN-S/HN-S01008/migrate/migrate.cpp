#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,d,a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int sum=0;
				for(int k=i+1;k<j;k++)
				{
					if(abs(a[k]-a[i])<=d&&abs(a[j]-a[k])<=d)
					{
						sum++;
						cout<<a[i]<<" "<<a[k]<<" "<<a[j]<<"\n";
					}
				}
				if(sum==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
