#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2005],st[2005],f[505][505],ans;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int k=1;k<=n;k++)
		{
			memset(f,0,sizeof(f));
			for(int i=k+1;i<=n;i++)
			{
				int z=lower_bound(a+1,a+1+n,(a[i]-d))-a;
				st[i]=st[z]+1;
			}
			f[k][0]=1;
			for(int i=k+1;i<=n;i++)
			{
				for(int j=1;j<=st[i];j++)
				{
					for(int t=i-1;t>=k;t--)
					{
						if(a[i]-a[t]>d)
							break;
						f[i][j]+=f[t][j-1];
					}
				}
			}
			for(int i=k;i<=n;i++)
			{
				if(f[i][st[i]]==2)
					ans++;
				st[i]=0;
			}
		}
		cout<<ans<<"\n";
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/