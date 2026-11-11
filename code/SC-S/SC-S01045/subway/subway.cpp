#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int c,n,m,d,q;
int sta[1010][30][3],t[N],pre[N],k,x,y,ans=INT_MAX;
struct node{
	int from,to,next;
}a[N];
void add(int u,int v)
{
	k++;
	a[k].from=u;
	a[k].to=v;
	a[k].next=pre[u];
	pre[u]=k;
}
void dfs(int xx,int cnt)
{
	if(xx==y)
	{
		ans=min(cnt,ans);
	}
	for(int i=pre[xx];i!=0;i=a[i].next)
	{
		dfs(i,cnt);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>sta[i][j][1]>>sta[i][j][2];
		}
		for(int j=1;j<=x;j++)
		{
			for(int k=j+1;k<=x;k++)
			{
				add(sta[i][j][1],sta[i][k][1]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		ans=INT_MAX;
		dfs(x,0);
		cout<<ans<<endl;
	}
	return 0;
}