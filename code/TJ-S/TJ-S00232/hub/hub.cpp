//好想被 OI 折磨成小楠梁 
//想要被温柔以待。 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ID,t;
int n,k;
vector<int> e[1000005];
namespace baoli//1~3
{
	int dis[1000005];
	bool vis[1000005];
	int calc(int status)
	{
		for(int i=1;i<=n;i++)
			dis[i]=0x3f3f3f3f;
		queue<int> q; 
		for(int i=1;i<=n;i++)
			if((status>>(i-1))&1)
				dis[i]=0,q.push(i);
		int ans=0;
		while(!q.empty())
		{
			int t=q.front();
			q.pop();
			ans=max(ans,dis[t]);
			for(int i:e[t])
				if(dis[t]+1<dis[i])
				{
					dis[i]=dis[t]+1;
					q.push(i);
				}
		}
		return ans;
	}
	void dfs(int id,int status)
	{
		vis[id]=true;
		for(int i:e[id])
			if((status&(1<<(i-1)))&&!vis[i])
			{
				vis[i]=true;
				dfs(i,status);
			}
	}
	bool check(int status)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			vis[i]=false;
		for(int i=1;i<=n;i++)
			if((status&(1<<(i-1)))&&!vis[i])
				dfs(i,status),cnt++;
		return cnt<=2;
	}
	void mian()
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int ans=n;
		for(int i=1;i<(1<<n);i++)
			if(__builtin_popcount(i)==k&&check(i))
				ans=min(ans,calc(i));
		cout<<ans<<"\n";
		return ;
	}
};
namespace A
{
	int a[2][1000005],b[1000005],dis[1000005];
	void dfs(int id,int last,int *h)
	{
		h[id]=h[last]+1;
		for(int i:e[id])
			if(i!=last)
				dfs(i,id,h);
	}
	queue<int> q;
	int calc(int u,int v)
	{
		while(!q.empty())
			q.pop();
		for(int i=1;i<=n;i++)
			dis[i]=0x3f3f3f3f;
		dis[u]=dis[v]=0;
		q.push(u),q.push(v);
		int ans=0;
		while(!q.empty())
		{
			int t=q.front();
			q.pop();
			ans=max(ans,dis[t]);
			for(int i:e[t])
				if(dis[t]+1<dis[i])
				{
					dis[i]=dis[t]+1;
					q.push(i);
				}
		}
		return ans;
	}
	void mian()
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0,a[0]);
		int u=-1,h=-1;
		for(int i=1;i<=n;i++)
			if(a[0][i]>h)
				u=i,h=a[0][i];
		dfs(u,0,a[0]);
		int v=-1;
		h=-1;
		for(int i=1;i<=n;i++)
			if(a[0][i]>h)
				v=i,h=a[0][i];
		dfs(v,0,a[1]);
		b[0]=u;
		int cur=0;
		while(b[cur]!=v)
		{
			for(int i:e[b[cur]])
			{
				if(a[0][i]==a[0][b[cur]]+1&&a[1][i]==a[1][b[cur]]-1)
				{
					b[++cur]=i;
					break;
				}
			}
		}
		int c[3]={0,0,0},ans=0x3f3f3f3f;
		if(cur%3==0)
		{
			c[0]=c[1]=c[2]=cur/3;
			ans=min(ans,calc(b[c[0]],b[c[0]+c[1]]));
		}
		else if(cur%3==1)
		{
			int lo=cur/3;
			for(int i=0;i<=2;i++)
			{
				c[0]=c[1]=c[2]=lo;
				c[i]=cur-lo*2;
				ans=min(ans,calc(b[c[0]],b[c[0]+c[1]]));
			}
		}
		else
		{
			int hi=(cur+1)/3;
			for(int i=0;i<=2;i++)
			{
				c[0]=c[1]=c[2]=hi;
				c[i]=cur-hi*2;
				ans=min(ans,calc(b[c[0]],b[c[0]+c[1]]));
			}
		}
		cout<<ans<<"\n";
		return ;
	}
};
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>ID>>t;
	for(int i=1;i<=t;i++)
	{
		if(ID==7||ID==11||ID==12)
			A::mian();
		else
			baoli::mian();
	}
	return 0;
}
//...
//短短四个小时荏苒而过
//... 
//在最后的最后，还是想要祝自己 CSP-S 2026 rp+=infinty
//预期得分:100+100+48+15=263
//...
//我不知道此刻我是否比一年前、两年前和三年前的自己更强了，因为我的 CSP-S 成绩是 125,220,229,(263) 
//我不知道这是否算得上是给我的最后一个 CSP-S 一个于心无愧的结局
//anyway,时间总会流逝,而我也总是被迫走向下一秒,首先我应该以一个积极的心态面对未来
//祝我今年能进入 TJOI 并获得银牌。 
