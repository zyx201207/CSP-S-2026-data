#include <bits/stdc++.h>
#define int long long 
const int INF=2e18;
const int N=2e6+10;
using namespace std;
int c,T;
int n,d;
int a[N];
int dis[N],cnt[N];
int ans;
bool vis[5005][5005];
struct node{
	int to,w;
	inline bool operator<(const node&tmp)const{
		return w>tmp.w;
	}
};
priority_queue<node>q;
vector<int>v[N]; 
inline void dij(int s)
{
	for(int i=1;i<=n;++i)
		dis[i]=INF,cnt[i]=0;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		auto t=q.top();
		q.pop();
		int x=t.to;
		int ju=t.w;
		if(ju>dis[x])
			continue;
		for(auto son:v[x])
		{
			if(dis[son]==1+ju)
			{
				cnt[son]++;
			}
			if(dis[son]>1+ju)
			{
				dis[son]=1+ju;
				cnt[son]=1;
				q.push({son,dis[son]});
			}
		}
	}
	return ;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				vis[i][j]=0;
				vis[j][i]=0;
			}
		}
		for(int i=1;i<=n;++i)
		{
			v[i].clear();
			cin>>a[i]; 
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				if(abs(a[i]-a[j])<=d)
				{
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;++i)
		{
			dij(i);
			for(int j=1;j<=n;++j)
			{
				if(cnt[j]==2&&vis[j][i]==0&&vis[i][j]==0)
				{
					//cout<<i<<" "<<j<<"\n";
					vis[i][j]=1;
					vis[j][i]=1;
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
/*
O(n*n)枚举两个点然后该怎么做呢
是不是可以跑最短路
如果dis[zh]的值相等那么这个值就++
如果出现比他更小的就清0,最后在统计cnt[x]==2的个数 
现在有一个建边的问题 
*/
