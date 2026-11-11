#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,s[5050],dis[5050][5050],ans,e[5050][5050];
void find()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		{
			if(i==k) continue;
			for(int j=1;j<=n;j++)
			{
				if(j==i || j==k) continue;
				if(dis[i][j]==1) e[i][j]=e[j][i]=1;
				if(dis[i][k]+dis[k][j]==dis[i][j])
				{
					e[i][j]++;e[j][i]++;
				}
				if(dis[i][k]+dis[k][j]<dis[i][j])
				{
					e[i][j]=e[j][i]==1;
					dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
				}
			}
		}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--)
	{
		ans=0;
		memset(dis,0x3f,sizeof(dis));
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&s[i]);
			dis[i][i]=0;
			for(int j=i-1;j>0;j--)
			{
				if(s[i]-s[j]<=d) dis[i][j]=dis[j][i]=1;
				else break;
			}
		}
		memset(e,0,sizeof(e));
		find();
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(e[i][j]==3) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}//不知道为什么骗分都不对 
