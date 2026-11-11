//SN-S00464 王均诚 陕西省西安中学
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int , int> PII;
const int N = 1e5;

int c , t;
ll n , k;
ll h[N] , w[N] , ne[N] , e[N] , idx;
bool st[N];
ll dist[N];

void add(int a , int b)
{
	e[idx] = b , w[idx] = 1 , ne[idx] = h[a] , h[a] = ++ idx;
}

int dijkstra()
{
	memset(dist , 0x3f , sizeof dist);
	dist[1] = 0;
	priority_queue<PII , vector<PII> , greater<PII> > heap;
	heap.push({0 , 1});
	
	while (heap.size())
	{
		auto t1 = heap.top();
		heap.pop();
		
		int ver = t1.first , dis = t1.second;
		
		if (st[ver]) continue;
		st[ver] = true;
		
		for (int i = h[ver] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if (dis[j] < dis[i] + w[i])
			{
				dis[j] = dis[i] + w[i];
				heap.push({dis[j] , j});
			}
		}
	}
	
	return dist[n - 1];
}

int main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , " w" , stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(h , -1 , sizeof h);
	memset(st , -1 , sizeof st);
	
	cin >> c >> t;
	while (t --)
	{
		cin >> n >> k;
		
		while (n > 1)
		{
			int u , v;
			cin >> u >> v;
			add(u , v);
		}
	
		
	}
	
	cout << dijkstra();
	return 0;
}
