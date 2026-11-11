#include<bits/stdc++.h>
using namespace std;
vector<int> w;
vector<unsigned int> vis;
vector<vector<pair<int,int>>> edges;
unsigned int tim = 0;
inline int read()
{
    char ch = getchar();
    int f = 1,num = 0;
    while(ch > '9' || ch <'0')
    {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        num = 10 * num + (ch - '0');
        ch = getchar();
    }
    return f * num;
}

inline void write(long long num)
{
	if(num == 0) 
	{
		putchar('0');
		return;
	}
	static char tmp[30];
	int idx = 0;
	int f = 1;
	if(num < 0) f = -1,num *= -1;
	while(num)
	{
		tmp[++idx] = (num % 10) + '0';
		num /= 10;
	}
	
	if(f < 0) putchar('-');
	while(idx) putchar(tmp[idx--]);
}

void init(int n,int m)
{
	w.assign(m + 1,0);
	edges.assign(n + m + 1,vector<pair<int,int>>());
	vis.assign(n + m + 1,0);
	tim = 0;
}

inline void add(int a,int b,int w)
{
	edges[a].emplace_back(b,w);
	edges[b].emplace_back(a,w);
}

long long dij(int x,int y)
{
	++tim;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> que;
	que.emplace(0,x);
	while(!que.empty())
	{
		
		long long a_w = que.top().first;
		int idx = que.top().second;
		que.pop();
		if(vis[idx] == tim) continue;
		vis[idx] = tim;
		
		if(idx == y) return a_w;
		
		for(pair<int,int> i : edges[idx])
		{
			int to = i.first;
			int b_w = i.second;
			
			if(vis[to] == tim) continue;
			
			que.emplace(a_w + b_w,to);
		}
	}
	
	return -1;
}

int main()
{   
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c = read();
    int n = read();
    int m = read();
    int d = read();
    int q = read();
    
    
    init(n,m);
    for(int i = 1;i <= m;i++) w[i] = read();
    
    for(int i = 1;i <= n;i++)
    {
    	int k;
    	k = read();
    	for(int j = 1;j <= k;j++)
    	{
    		int a = read();
    		int t = read();
    		add(m + i,a,t);
		}
	}
	
	
	
	for(int i = 1;i <= q;i++)
	{
		int x = read();
		int y = read();
		write(dij(x,y) + w[x] + w[y]);
		putchar('\n');
	}
	
	/*
	for(int i = 1;i <= n + m;i++)
	{
		if(i <= m) printf("地铁%d链接: ",i);
		else printf("站点%d链接: ",i - m);
		for(int j = 0;j < edges[i].size();j++)
		{
			int idx = edges[i][j].first;
			if(idx <= m) printf("地铁%d ",idx);
			else printf("站点%d ",idx - m);
		} 
		putchar('\n');
	} 
	*/
	
    return 0;
}
