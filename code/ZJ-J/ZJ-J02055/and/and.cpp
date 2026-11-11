#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mx=-1;
int head[20000005],tot,vis[200005],dis[200005];
//queue<int> q;
//struct E{
//	int to,w,next;
//}e[20000005];
//bool add(int u,int v,int w)
//{
//	e[++tot].to=v;
//	e[tot].w=w;
//	e[tot].next=head[u];
//	head[u]=tot;
//}
//void spfa(int u)
//{
//	q.push(u);
//	memset(vis,0,sizeof(vis));
//	for(int i=1;i<=200000;i++)dis[i]=-1;
//	while(!q.empty)
//	{
//		int k=q.front();
//		q.pop();
//		for(int i=k;)
//	}
//}
void dfs(int i,int s,int sum)
{
	if(s==m)
	{
		mx=max(mx,sum);
		return ;
	}
	if(i==n)return ;
	dfs(i+1,s+1,sum&a[i+1]);
	dfs(i+1,s,sum);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n)
	{
		int sum=a[1];
		for(int i=1;i<=n;i++)sum=sum&a[i];
		cout<<sum;
		return 0;
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		int maxx=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(n<=20)
	{
		dfs(0,0,63);
		cout<<mx;
		return 0;
	}
	sort(a+1,a+n+1);
	int sum=a[n-1];
	for(int i=n-1;i>=n-m;i--)sum=sum&a[i];
	cout<<sum;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=i+1;j<=n;j++)
//		{
//			add(a[i],a[j],a[i]&a[j]);
//		}
//	}
//	for(int i=1;i<=n;i++)
//	{
//		spfa(i);
//		for(int j=1;j<=n;j++)
//		{
//			
//			mx=max(mx,dis[j]);		
//		}
//	}
//	cout<<mx;
	return 0;
}

