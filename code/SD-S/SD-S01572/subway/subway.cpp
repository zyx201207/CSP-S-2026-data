#include <bits/stdc++.h>
using namespace std;
# define int long long
int a1[20][20],a2[20][20],a[20],x,y,b[20][20],flag=0,minn=5e5+10;
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	int w[20];
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		for(int j=1; j<=a[i]; j++) {
			cin>>a1[i][j]>>a2[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			for(int t=1; t<=a[i]; t++) {
				for(int k=1; k<=a[j]; k++) {
					if(a1[i][t]==a1[j][k]&&((b[i][j]>(a2[i][t]+a2[j][k]))||(b[i][j]==0))) {
						b[i][j]=a2[i][t]+a2[j][k];
						b[j][i]=a2[i][t]+a2[j][k];
					}
				}
			}
		}
	}
	while(p--) {
		cin>>x>>y;
		int e[3][4],f[2][4],t=0,k=0;
		for(int i=1; i<=n; i++) 
		{
			for(int j=1;j<=a[i];j++)
			{
				if(a1[i][j]==x)
				{
					e[1][++k]=i;f[1][k]=a2[i][j];
				}
				if(a1[i][j]==y)
				{
					e[2][++t]=i;f[2][t]=a2[i][j];
				}
			}
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=t;j++)
			{
				if(e[1][i]==e[2][j])
				{
					minn=min(minn,f[1][i]+f[2][j]);
				}
			}
		}
		if(n==2||n==3)
		{
			for(int i=1;i<=k;i++)
			{
				for(int j=1;j<=t;j++)
				{
					if(b[e[1][i]][e[2][j]]>0) minn=min(minn,(b[e[2][j]][e[1][i]]+f[1][i]+f[2][j]));
				}
			}
		}
		if(n==3)
		{
			for(int i=1;i<=k;i++)
			{
				for(int j=1;j<=t;j++)
				{
					if(e[1][i]==1)
					{
						if(e[2][i]==2)
						{
							if((b[1][3]>0)&&(b[2][3]>0))
							{
								minn=min(minn,b[1][3]+b[2][3]+f[1][i]+f[2][i]);
							}
						}
					}
					if(e[1][i]==1)
					{
						if(e[2][i]==3)
						{
							if((b[1][2]>0)&&(b[3][2]>0))
							{
								minn=min(minn,b[1][2]+b[2][3]+f[1][i]+f[2][i]);
							}
						}
					}if(e[1][i]==3)
					{
						if(e[2][i]==2)
						{
							if((b[1][3]>0)&&(b[2][1]>0))
							{
								minn=min(minn,b[1][3]+b[2][1]+f[1][i]+f[2][i]);
							}
						}
					}
				}
			}
		}
		cout<<w[x]+w[y]+minn<<endl;
	}
}
