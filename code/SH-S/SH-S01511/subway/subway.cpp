#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100005],t[100005],x,y,k,ans,minn,maxn,p,flag=0,mm,cnt;
long long val[505][100005],u[505][100005];
void dfs(int a,int e)
{
	    int b;
	    b=u[a][e];
		flag=0;
		if(b==y)
		{
			ans+=val[a][e]; 
			minn=min(minn,ans);
			return;
		}
		else if(u[a][e]==-1)
		return;
		else
		{
			flag=0;
			cnt=0;
			for(int i=1;i<=maxn;i++)
			{
				if(b==u[a+1][i])
				{
				flag=1;
				mm=i;
				break;
				}
			}
			if(flag)
			{
			
			ans+=val[a+1][mm];
			ans+=val[a][e];
			dfs(a+1,e);
			}
			else
			{
			ans+=val[a][e];
			dfs(a,e+1);
			}
		
		} 
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0)
	c=1;
	for(int i=1;i<=c;i++)
	{
		maxn=-1;
		for(int j=1;j<=m;j++)
		cin>>w[j];
		for(int j=1;j<=n;j++)
		{
			cin>>k;
			maxn=max(maxn,k); 
			for(int l=1;l<=k;l++)
			{
			u[j][l]=-1;
			val[j][l]=-1;
			}
			for(int l=1;l<=k;l++)
			cin>>u[j][l]>>val[j][l];
		}
		for(int j=1;j<=q;j++)
		{
			ans=0;
			minn=1e18;
			cin>>x>>y;
			dfs(x,1);
			cout<<minn+w[x]+w[y]<<endl;
		}
	}
	return 0;
}
