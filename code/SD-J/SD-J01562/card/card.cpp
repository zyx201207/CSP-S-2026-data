#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int N=5e5+10;
ll a[N];
int ed[N];
ll ans[N];
ll sum[N];
ll cnt;
int st[N];
bool vis[N];
int inl[N]; 
void slove1()
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[a[i]])
		{
			vis[a[i]]=1;
			int j=i;
			while(j<=n)
			{
				j=ed[a[j]];
				ans[a[j]]+=sum[a[i]];
				j=j+1;
			}
		}
		
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
} 
//void slove2()
//{
//	for(int i=2;i<=n;i++)
//	{
//		if(a[i]!=a[i-1]&&ed[a[i-1]]==i-1)
//		{
//			int x=a[i],y=a[i-1];
//			if(x>y) swap(x,y)
//			if(mp.count({a[i-1],a[i]}))
//				g[a[i-1]].push_back(a[i]),inl[a[i]]++
//		}
//		
//	}
//	for(int i=1;i<=m;i++) 
//	{
//		if(!inl[i]) q.push({i,sum[i]});
//		ans[i]=sum[i];
//	}
//	while(!q.empty())
//	{
//		auto x=q.front();
//		q.pop();
//		int u=x.first;
//		int w=x.second;
//		for(int v:g[u])
//		{
//			inl[v]--;
//			if(!inl[v])
//			{
//				ans[v]+=w;
//				q.push({v,ans[v]});
//			}
//		}
//	}
//	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
//}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ed[a[i]]=i;
		if(!st[a[i]]) st[a[i]]=i;
		sum[a[i]]++;
		if(a[i]<a[i-1]) flag=0;
	}
	if(flag)
	{
		for(int i=1;i<=m;i++) cout<<ed[i]<<" ";
	}else
	{
		slove1();
	}
	return 0;
 } 

