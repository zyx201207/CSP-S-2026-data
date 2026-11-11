#include<bits/stdc++.h>
using namespace std;
long long w[500005],t[505][50005],ans;
int c,n,m,d,q,a,k,x,y;
bool r[500005];
void dfs(int x,int y,long long ans_)
{
	r[x]=1;
	r[y]=0;
	if(x==y) ans=min(ans,ans_);
	for(int i=1;i<=n;i++)
	{
		if(t[i][x]!=0)
		{
			for(int j=1;j<=m;j++)
			{
				if(j!=x&&t[i][j]!=0&&r[j]==0)
				{
					dfs(j,y,ans_+t[i][x]+t[i][j]);
				}
			}
		}
	}
	r[x]=0;
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a;
			cin>>t[i][a];
		}
	}
	while(q--)
	{
		ans=999999999999999;
		cin>>x>>y;
		dfs(x,y,w[x]+w[y]);
		cout<<ans<<'\n';
		for(int i=1;i<=m;i++) r[i]=0;
	}
	return 0;
}
