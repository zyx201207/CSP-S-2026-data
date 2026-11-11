#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,a[2000005],jl[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		int ans=0;
		for(int j=1;j<n;j++)
		{
			jl[j]=a[j+1]-a[j];
		}
		for(int j=1;j<n;j++)
		{
			for(int k=j+2;k<n;k++)
			{
				int num=0;
				for(int f=j+1;f<k;f++)
				{
					num+=jl[f];
				}
				if(jl[j]==jl[k]&&(jl[j]+num<=d))
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 