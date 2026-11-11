#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define int long long

namespace Migrate
{
using namespace std;

const int N=2e6+5;

int island_cnt=0;
int max_distance=0;
int island_pos[N];
int ans=0;

vector<vector<int>>graph;

void input()
{
	cin>>island_cnt>>max_distance;
	graph.resize(island_cnt+5);
	for(int i=1; i<=island_cnt; i++)
	{
		cin>>island_pos[i];
	}
}

int spfa(int start)
{
	queue<int>q;
	vector<int>distance(island_cnt+5,INT_MAX);
	distance[start]=0;
	vector<int>cnt(island_cnt+5,0);
	cnt[start]=1;
	q.push(start);

	while(!q.empty())
	{
		int island1=q.front();
		q.pop();

		for(auto island2:graph[island1])
		{
			if(distance[island1]+1<distance[island2])
			{
				distance[island2]=distance[island1]+1;
				cnt[island2]=cnt[island1];
				q.push(island2);
			}
			else if(distance[island1]+1==distance[island2])
			{
				cnt[island2]+=cnt[island1];
				q.push(island2);
			}
		}
	}
	int res=0;
	for(int i=1; i<=island_cnt; i++)
	{
		if(cnt[i]==2)++res;
	}
	return res;
}

void solve()
{
	for(int i=1; i<=island_cnt; i++)
	{
		for(int j=i+1; j<=island_cnt; j++)
		{
			if(island_pos[j]-island_pos[i]<=max_distance)
				graph[i].push_back(j);
		}
	}
	for(int i=1; i<=island_cnt; i++)
	{
		ans+=spfa(i);
	}
}
void output()
{
	cout<<ans<<endl;
}

int main()
{
	memset(island_pos,0,sizeof(island_pos));
	graph.clear();
	input();
	solve();
	output();
	return 0;
}
}

signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int test_id,t;
	std::cin>>test_id>>t;
	while(t--)
		Migrate::main();

	return 0;
}
