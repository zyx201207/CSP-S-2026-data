#include<bits/stdc++.h>
using namespace std;
int ttttt,T,n,t;
long long m,a[2000005],b[2000005][2],f[5005][5005],g[5005][5005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>ttttt>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i][0]=b[i][1]=0;
		}
		t=1;
		for(int i=1;i<=n;i++)
		{
			while(a[i]-a[t]>m)
			{
				b[t][1]=i-1;
				t++;
			}
			b[i][0]=t;
		}
		while(t<=n)
		{
			b[t][1]=n;
			t++;
		}
		if(ttttt<=10)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					f[i][j]=0;
					g[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++)
			{
				t=i;
				while(t<n && b[t][1]>t)
				{
					for(int j=t+1;j<=b[t][1];j++)
					{
						f[i][j]=f[i][t]+1;
					}
					t=b[t][1];
				}
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(b[i][1]>=j)
					{
						g[i][j]=1;
					}
					else
					{
						for(int k=j-1;k>i;k--)
						{
							if(b[k][1]<j)
							{
								break;
							}
							if(f[i][j]==f[i][k]+f[k][j])
							{
								g[i][j]+=g[i][k];
							}
						}
					}
					if(g[i][j]==2)
					{
						ans++;
					}
				}
			}
			cout<<ans<<endl;	
		}
		else
		{
			t=b[1][1]+1;
			for(int i=1;i<=n;i++)
			{
				while(b[i][1]>=t && t<=n)
				{
					t++;
				}
				while(b[i][1]-b[t][0]>1 && t<=n)
				{
					t=t+1;
				}
				if(t>n)
				{
					break;
				}
				if(b[i][1]-b[t][0]==1)
				{
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}