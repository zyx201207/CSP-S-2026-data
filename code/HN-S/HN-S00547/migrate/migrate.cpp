#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,f[120005][2],s=0;
	long long a[120005];
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int l=1;l<=n;l++)
		{
			f[l][0]=0;
			f[l][1]=1;
			for(int j=l+1;j<=n;j++)
			{
				f[j][0]=120009;
				f[j][1]=0;
				for(int k=j-1;a[k]+d>=a[j]&&k>=l;k--)
				{
					f[j][0]=min(f[j][0],f[k][0]);
				}
				for(int k=j-1;a[k]+d>=a[j]&&k>=l;k--)
				{
					if(f[k][0]==f[j][0])
					{
						f[j][1]+=f[k][1];
					}
				}
				f[j][0]++;
				if(f[j][1]==2)
				{
					s++;
				}
			}
		}
		cout<<s<<endl;
		s=0;
	}
	return 0;
}
