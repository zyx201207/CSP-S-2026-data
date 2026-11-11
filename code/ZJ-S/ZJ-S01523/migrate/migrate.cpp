#include<bits/stdc++.h>
#define int long long
using namespace std;

int k,i,j,n,D,T,c,ans,mi,fl,f[310][310],a[310];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>D;ans=0;
		for(i=1;i<=n;i++)
			cin>>a[i];
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				f[i][j]=1e16;
		for(i=1;i<=n;i++)f[i][i]=0;
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=D)
					f[i][j]=f[j][i]=1;
			}
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(j-i<D+1)continue;mi=1e16;fl=0;
				for(k=i+1;k<=j-1;k++)
				{
					if(f[i][k]==2e9||f[k][j]==2e9)continue;
					if(f[i][k]+f[k][j]<mi)
						mi=f[i][k]+f[k][j],fl=1;
					else if(f[i][k]+f[k][j]==mi)fl++;
				}
				if(fl==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
