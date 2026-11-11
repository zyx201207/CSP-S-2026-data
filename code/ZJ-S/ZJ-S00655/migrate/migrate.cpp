#include<iostream>
#include<queue>
#define Max 2000005
namespace my
{
	using std::cin;
	using std::ios;
	using std::queue;
	using std::pair;
	using std::cout;
}
using namespace my;
int c;//测试点编号(垃圾) 
int t;//测试点数 
int n;//岛屿数量 
long long d;//能飞最长距离 
long long a[Max];//岛屿坐标
queue<pair<int,int>> que;pair<int,int> head;
bool dfs(int start,int end)
{
	long long less=2e9;
	int cnt=0;
	que.push({start,0});
	while(!que.empty())
	{
		head=que.front();que.pop();
		if(head.second>less)
			continue;
		if(head.first==end)
		{
			if(less>head.second)
			{
				less=head.second;
				cnt=1;
			}
			else if(less==head.second)
			{
				++cnt;
			}
			break;
		}
		for(int i=head.first+1;a[head.first]+d>=a[i];++i)
		{
			que.push({i,head.second+1});
		}
	}
	if(cnt==2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int ans;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		for(int l=1;l<=n;++l)
		{
			for(int r=l+2;r<=n;++r)
			{
				if(dfs(l,r))
				{
					++ans;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
