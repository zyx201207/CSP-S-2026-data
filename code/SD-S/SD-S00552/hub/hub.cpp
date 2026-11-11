#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=2e6+5;
int c,T;
int n,k;
vector<int> g[N];
int fa[N];
inline int root(int x){return fa[x]==x?x:fa[x]=root(fa[x]);}
inline void merge(int x,int y)
{
	x=root(x);
	y=root(y);
	fa[x]=y;
}
inline int count(int u)
{
	int res=0;
	while(u)
	{
		if(u&1)	res++;
		u>>=1;
	}
	return res;
}
int cnt;
int ans=0x3f3f3f3f;
bool vis[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		
		for(int i=1;i<=n;i++)	g[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		int tot=(1<<n);
		ans=0x3f3f3f3f;
		for(int i=0;i<tot;i++)
		{
			cnt=0;
			if(count(i)!=k)	continue;
			for(int i=1;i<=n;i++)	fa[i]=i;
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j))
				{
					bool f=1;
					for(auto k:g[j+1])
					{
						if(fa[j+1]==fa[k])
							f=0;
						else
							merge(j+1,k);
					}
					cnt+=f;
				}
			}
			if(cnt>2)	continue;
			//枚举k个合理城市 
			
			for(int j=0;j<n;j++)
			{
				int tmp=-0x3f3f3f3f;
				if(!(i&(1<<j)))	//不在S集合中 
				{					
					memset(vis,0,sizeof vis);
					queue<pii> q;
					q.push({0,j+1});
					while(!q.empty())
					{
						int pos=q.front().second;
						int val=q.front().first;
						q.pop();
						if(vis[pos])	continue;
						vis[pos]=1;
						for(auto k:g[pos])
						{
//							
							q.push({val+1,k});
							if(i&(1<<(k-1)))	//选这一个了 
							{
								tmp=max(tmp,val+1);	//更新答案 
							}
						}
					}
					ans=min(ans,tmp);
				}
				
			}
		}
		
		cout<<ans-1<<"\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/
