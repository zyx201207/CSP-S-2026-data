#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>

const int N = 101010;

int h[N],e[N],w[N],ne[N];
int times[N];
int idx;
int dist[N];
bool st[N];
int c,n,m,d,q;
int a,b,k;

void add(int u,int v,int c) {
	e[idx] = v;
	w[idx] = c;
	ne[idx] = h[u];
	h[u] = idx ++;
}

int dij(int s,int t) {
	memset(dist,0x3f,sizeof(dist));
	memset(st,false,sizeof(st));
	dist[s] = 0;
	priority_queue<PII,vector<PII>,greater<PII> > heap;
	heap.push(make_pair(0,s));
	while(!heap.empty()) {
		PII now = heap.top();
		heap.pop();
		int distance = now.first;
		int ver = now.second;
		if(st[ver]) continue;
		st[ver] = true;
		for(int i = h[ver];i != -1;i = ne[i]) {
			int j = e[i];
			if(dist[j] > w[i] + distance) {
				dist[j] = min(dist[j],w[i] + distance);
			}
			if(!st[j]) heap.push(make_pair(dist[j],j));
		}
	}
	return dist[t];
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	memset(h,-1,sizeof(h));
	for(int i = 1;i <= m;i ++) {
		cin >> times[i];
		add(i,i + m,times[i]);
		add(i + m,i,times[i]);
	} 
	
	for(int i = 1;i <= n;i ++) {
		cin >> k;
		for(int j = 1;j <= k;j ++) {
			cin >> a >> b;
			add(2 * m + i,m + a,b);
			add(m + a,2 * m + i,b);
		}
	}
	
	for(int i = 1;i <= q;i ++) {
		int x,y;
		cin >> x >> y;
		cout << dij(x,y) << "\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
