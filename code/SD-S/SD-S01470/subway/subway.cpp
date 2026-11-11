#include<bits/stdc++.h>
#define int long long

namespace Subway
{
using namespace std;

struct Edge
{
	int station,time;
};

int test_id=0;
int subway_cnt=0,station_cnt=0;
int max_subway=0;
int plan_cnt=0;

vector<vector<Edge>>graph;
vector<int>time_to_station;
vector<pair<int,int>>plans;

void input()
{
	cin>>test_id;
	cin>>subway_cnt>>station_cnt;
	cin>>max_subway;
	cin>>plan_cnt;

	graph.resize(station_cnt+5);
	time_to_station.resize(station_cnt+5);
	plans.resize(plan_cnt+5);

	for(int i=1; i<=station_cnt; i++)
	{
		cin>>time_to_station[i];
	}

	for(int i=1; i<=subway_cnt; i++)
	{
		int k=0;

		cin>>k;

		vector<int>a(k+5,0);
		vector<int>t(k+5,0);

		for(int i=1; i<=k; i++)
		{
			cin>>a[i]>>t[i];
		}

		for(int i=1; i<=k; i++)
		{
			for(int j=i+1; j<=k; j++)
			{
				graph[a[i]].push_back({a[j],t[i]+t[j]});
				graph[a[j]].push_back({a[i],t[i]+t[j]});
			}
		}
	}

	for(int i=1; i<=plan_cnt; i++)
	{
		cin>>plans[i].first>>plans[i].second;
	}
}

int solve(int start_station,int end_station)
{
	queue<int>q;
	vector<int>distance(station_cnt+5,1e9);
	q.push(start_station);
	distance[start_station]=0;

	while(!q.empty())
	{
		int station1=q.front();
		q.pop();

		for(auto p:graph[station1])
		{
			int station2=p.station,time=p.time;
			if(distance[station1]+time<distance[station2])
			{
				distance[station2]=distance[station1]+time;
				q.push(station2);
			}
		}
	}

	return distance[end_station];
}

void output()
{
	for(int i=1; i<=plan_cnt; i++)
	{
		int start_station=plans[i].first;
		int end_station=plans[i].second;
		cout<<solve(start_station,end_station)
		    +time_to_station[start_station]
		    +time_to_station[end_station]
		    <<endl;
	}
}

int main()
{
	input();
	output();
	return 0;
}
}

signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	Subway::main();

	return 0;
}
