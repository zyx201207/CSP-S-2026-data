#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

typedef long long LL;

const int M = 5e5 + 10; // 地铁站 个数 
const int N = 5e2 + 10; // 地铁 线路个数
const LL INF = 0x3f3f3f3f3f3f3f3f; 

struct Node
{
	int idx; // 经过地铁站编号 
	int t; // 地铁站 -> 站厅的时间 
};

int c = 0;
int n = 0; // 地铁线路数 
int m = 0; // 地铁站数 
int d = 0; // 每个地铁站 至多 被 d 条线路 经过 
int q = 0; // 问题数量 

int w[M]; // 地铁口 -> 站厅 的时间 
int k[N]; // 线路 i 经过的 地铁站数 

vector<Node> sline[N]; // sline[i] => 线路 i 经过的 地铁站

vector<Node> vlist[M]; // vlist[i] => 地铁站 i 经过的线路

LL dist[M]; 

priority_queue< pair<LL, int> > qlist;

LL dij(int root, int tar)
{
	pair<LL, int> tmp;
	
	LL d = 0;
	LL arv = 0;
	LL val = 0;
	
	int x = 0;
	int y = 0;
	int idx = 0;
	
	LL res = 0;
	
	while(!qlist.empty())
	{
		qlist.pop();
	}
	
	memset(dist, 0x3f, sizeof(dist));
	
	tmp.first = 0;
	tmp.second = root;
	
	qlist.push(tmp);
	
	while(!qlist.empty())
	{
		tmp = qlist.top();
		qlist.pop();
		
		x = tmp.second;
		d = -tmp.first;
		
		if(dist[x] < d)
		{
			continue;
		}
		
		if(x == tar)
		{
			res = dist[x];
			
			break;
		}
		
		for(int i = 0; i < vlist[x].size(); i++) 
		{
			idx = vlist[x][i].idx; // 遍历 地铁站 x 经过的线路
			
			arv = d + vlist[x][i].t; // 到达 站台 
			
			for(int j = 0; j < sline[idx].size(); j++)
			{
				y = sline[idx][j].idx; // 遍历 停靠位置 
				val = sline[idx][j].t;
				
				if(arv + val < dist[y])
				{
					dist[y] = arv + val;
					
					tmp.first = -dist[y];
					tmp.second = y;
					
					qlist.push(tmp);
				}
			}
		}
	}
	
	res += w[root] + w[tar]; // 各自走到 地铁口 
	
	return res;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);  
	
	int x = 0;
	int y = 0;
	
	LL res = 0;
	
	Node tnode;
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		
		for(int j = 1; j <= k[i]; j++)
		{
			cin >> tnode.idx >> tnode.t; // 地铁站编号 + 时间 
			
			vlist[tnode.idx].push_back({i, tnode.t});
			// id 地铁站 站厅 到 i 条线路 站台的 时间 
			
			sline[i].push_back(tnode);
		}
	}
	
	while(q--)
	{
		cin >> x >> y;
		
		res = dij(x, y);
		
		cout << res << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
