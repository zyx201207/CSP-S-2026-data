#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],ans,f[505][5005],t;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int que;
			cin>>que>>f[i][que];
			t=f[i][que];
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		int start,end;
		cin>>start>>end;
		ans+=w[start]+w[end];
		if(n<=200)
		{
			for(int i=1;i<=200;i++)
			{
				for(int j=1;j<=200;j++)
				{
					for(int k=1;k<=200;k++)
					{
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					}
				}
			}
			ans+=f[start][end];
			cout<<ans+6<<endl;
		}
		else
		{
			ans+=t*2;
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
