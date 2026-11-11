#include <bits/stdc++.h>

using namespace std;

#define gc() getchar()
#define pc(x) putchar(x)

int read()
{
	int x=0,f=1;
	char c=gc();
	while(!isdigit(c)) {if(c=='-') {f=-f;}c=gc();}
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=gc();
	}
	return x*f;
}

void write(int x)
{
	if(x<0) {pc('-');x=-x;}
	if(x<10) {pc(x+'0');return ;}
	write(x/10);pc(x%10+'0');
	return ;
}

void print(int x)
{
	write(x);pc('\n');
	return ;
}

int n,T,c,k;
vector<int> e[1010];
bool vis[1010];
int a[1010][1010];
bool v[1010];
bool isk(int x)
{
	int cnt=0;
	while(x) {cnt++;x=x&(x-1);}
	return (k==cnt);
}

void dfs(int x)
{
	vis[x]=1;
	for(auto to:e[x])
	{
		if(!vis[to]) {dfs(to);}
	}
	return ;
}

bool check(int x)
{
	if(!isk(x)) {return false;}
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;v[i]=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(x&1) {vis[i]=0;v[i]=1;}
		x>>=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) {cnt++;dfs(i);}
		if(cnt>2) {return false;}
	}
	return true;
}

void solve1()
{
	while(T--)
	{
		n=read();k=read();
		int ans=1e9;
		for(int i=1;i<=n;i++)
		{ 
			e[i].clear();
			for(int j=1;j<=n;j++)
			{
				a[i][j]=1e9;
			}
			a[i][i]=0;
		}
		for(int i=1;i<n;i++)
		{
			int u=read(),v=read();
			e[u].push_back(v);
			e[v].push_back(u);
			a[u][v]=a[v][u]=1;
		}
		for(int opt=3;opt<(1<<n);opt++)
		{
			if(check(opt))
			{
				for(int k=1;k<=n;k++)
				{
					for(int i=1;i<=n;i++)
					{
						for(int j=1;j<=n;j++)
						{
							a[j][i]=a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
						}
					}
				}
				int maxn=0;
				for(int i=1;i<=n;i++)
				{
					if(v[i]) {continue;}
					int minn=1e9;
					for(int j=1;j<=n;j++)
					{
						if(v[j])
						{
							minn=min(minn,a[i][j]);
						}
					}
					maxn=max(maxn,minn);
				}
				ans=min(ans,maxn);
			}
		}
		print(ans);
		
	}
	return ;
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();T=read();
	if(c<=3) {solve1();return 0;}
	
	
	return 0;
}

/*
从风亲吻我的那一天起 我的故事开始了
可风将我带来 却没告诉我该怎么活
我以为 人生是旷野 是我的舞台
可后来我发现 旷野是他们的 而背景是我
我也想有一天成为那意气风发的某某
江南说 每朵野菊花都有他绽放的一天
可我何时能绽放
江南是绽放的 可他本就来自北京大学 还能写下《龙族》
他笔下的路明非是绽放的 可路明非天生就是S级天赋 
他写下衰小孩的成长之旅送给我们 可我们也无法进入我们的卡塞尔学院
我渴望绽放
可我不是路明非 能用生命和路鸣泽交换力量
可我的生命廉价
或许过完了这一生也寂寂无名
就像这世界也不是努力就能出结果
世上的烦心事已经够多了
若我仍将心事困于繁文琐事中
我的人生大抵已经结束了
.*/

