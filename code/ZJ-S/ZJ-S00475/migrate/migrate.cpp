#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,m,a[2000010];
struct node
{
	int dis,num;
}f[5010][5010];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j].dis=-1;
				if(i==j)
					continue;
				int tmp=abs(a[i]-a[j]);
				if(tmp<=m)
				{
					f[i][j].dis=1;
					f[i][j].num=1;
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				if(i==k||f[i][k].num==0||f[i][k].num>=3)
					continue;
				for(int j=1;j<=n;j++)
				{
					if(i==j||j==k||f[j][k].num==0||f[j][k].num*f[i][k].num>=3)
						continue;
					int l=f[i][k].dis+f[j][k].dis;
					if(f[i][j].dis==-1)
						f[i][j].dis=217483647;
					if(l>f[i][j].dis)
						continue;
					else if(l==f[i][j].dis)
						f[i][j].num+=f[i][k].num*f[j][k].num;
					else
					{
						f[i][j].num=f[i][k].num*f[j][k].num;
						f[i][j].dis=l;
					}
				}
			}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//				printf("%5d",f[i][j].dis);
//			cout<<endl;
//		}
//		cout<<endl;
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//				printf("%5d",f[i][j].num);
//			cout<<endl;
//		}
//		cout<<endl<<endl;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				if(f[i][j].num==2)
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}

