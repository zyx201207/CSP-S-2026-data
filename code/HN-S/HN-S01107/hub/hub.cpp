/*
5.31
enjoy coding 1

5.44
已燃尽， 
100+100+40+ (rand()%4) * 5;
求个1=
上午红橙黄绿，下午为啥不是青蓝紫黑
啊吧啊吧，感觉会有人:
crystal -> crytal
subway -> subwat
migrate -> migrote
hub -> hib 
今年雷霆解压密码居然不是上善若水人杰地灵
Oct31==Dec25?
这是csps = noip吗？ 
*/
/*
小 W 为什么要研究？ 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 16;
int n,k;
vector<int> e[N];
bool ava[N];
bool vis[N];

void checkdfs(int x,int fa)
{
	vis[x] = 1;
	for(auto i : e[x])
	{
		if(i == fa || !ava[i])	continue;
		checkdfs(i,x);
	}
}

bool check()
{
	int cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(ava[i] && !vis[i])
		{
			checkdfs(i,i);
			cnt++;
		}
	}
	if(cnt > 2)	return 0;
	return 1;
}

int d[N];
int ans = 1e18;
void dfs(int x,int fa)
{
	for(auto i : e[x])
	{
		if(i == fa)	continue;
		if(d[i] <= d[x]+1)	continue;
		d[i] = d[x]+1;
		dfs(i,x);
	}
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(0);
	int T;
	cin>>T>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int tans=1e18;
		for(int i=1;i<(1<<n);i++)
		{
			int cnt=0;
			memset(d,0x3f,sizeof(d));
			for(int j=1;j<=n;j++)
			{
				if(i & (1<<j-1))
				{
					ava[j]=1;cnt++;
				}else	ava[j]=0;
			}
			if(cnt != k)	continue;
			if(!check())	continue;
//			cout<<bitset<7>(i)<<endl;
			for(int i=1;i<=n;i++)
			{
				if(!ava[i])	continue;
				d[i] = 0;
//				cout<<i<<endl;
				dfs(i,i);
			}
			ans=0;
			for(int i=1;i<=n;i++)
			{
				ans = max(ans,d[i]);
			}
//			cout<<ans<<endl;
			tans = min(tans,ans);
		}
		cout<<tans<<endl;
		
	}
	return 0;
 } 
