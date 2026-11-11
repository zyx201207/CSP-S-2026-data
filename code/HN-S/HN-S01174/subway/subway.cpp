#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to,next,time;
}e[2000005];
int head[2000005],cnt;

inline void add_edge(int x,int y,int w) {
	e[++cnt].to = y;
	e[cnt].next = head[x];
	head[x] = cnt;
	e[cnt].time = w;
}
int n,m,d,q;
int t[500005];

inline int bfs(int start,int end) {
	queue< pair<int,int> > q;
	bool vis[500005];
	q.push(make_pair(start,0));
	vis[start] = true;
	while(!q.empty()) {
		int fa = q.front().first;q.pop();
		for(register int i = head[fa];i;i = e[i].next) {
			int v = e[i].to;
			if(v != fa) {
				if(!vis[v]) {
					q.push(make_pair(v,e[v].time+e[fa].time));
				}
			}
			if(v == fa) {
				return e[v].time + t[fa] + t[v];
			}
		}
	}
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&n,&n,&m,&d,&q);
	for(register int i = 1;i <= m;i++) scanf("%d",&t[i]);
	for(register int i = 1;i <= n;i++) {
		int x;
		scanf("%d",&x);
		int last_s;
		while(x--) {
			int s,t;
			scanf("%d %d",&s,&t);
			if(last_s != 0) add_edge(s,last_s,0);
			add_edge(s,s+n,t);
		}
	}
	while(q--) {
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%d\n",bfs(x,y));
	}
	return 0;
}
