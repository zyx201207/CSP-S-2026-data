#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],k,fx[35],f[35],ans,x,maxx,z;
bool ak[200005][35],af[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	fx[0]=1;
	for(int i=1;i<=31;i++)
	fx[i]=fx[i-1]*2;
	cin>>n>>m;
	maxx=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x=a[i];
		k=0;
		while(x!=0)
		{
			if(x-x/2*2==1)
			{
				f[k]++;
				ak[i][k]=1;
			}
			if(f[k]>=m&&k>=maxx)
			maxx=k;
			k++;
			x/=2;
			
		}
	}
	while(maxx!=-1)
	{
		ans+=fx[maxx];
		z=maxx;
		maxx=-1;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			if(ak[i][z]==1&&af[i]==0)
			{
				for(int j=0;j<z;j++)
				{
					f[j]+=ak[i][j];
					if(f[j]>=m&&j>=maxx)
					maxx=j;
				}
			}
			else
			af[i]=1;
		}
	}
	cout<<ans;
	return 0;
}
