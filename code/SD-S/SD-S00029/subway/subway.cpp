#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int maxs = 555,maxn = 555555,maxm = maxn*2;
long long read(){
	char c = getchar();
	int f = 1;
	while(c < '0' || c > '9'){
		if(c == '-')f = -1;
		c = getchar();
	}
	
	long long ans = 0;
	while('0' <= c && c <= '9'){
		ans = ans*10 + c - '0';
		c = getchar();
	}
	ans = ans*f;
	
	return ans;
}
int c,n,m,most,q;
long long cost[maxn];
//int k[maxs];
//int a[maxs][maxn],t[maxs][maxn];
int e[maxm],ne[maxm],h[maxn],w[maxm],idx;
void init(){
	memset(h,-1,sizeof(h));
	idx = 0;
}
void add(int a,int b,int c){
	e[idx] = b,ne[idx] = h[a],w[idx] = c,h[a] = idx++;
}
long long d[555555];
bool st[maxn];
void dijkstra(int S){
	memset(d,0x3f,sizeof(d));
	memset(st,false,sizeof(st));
	priority_queue<PII,vector<PII>,greater<PII> > heap;
	d[S] = 0;
	st[S] = 0;
	heap.push({0,S});
	
	while(!heap.empty()){
		PII t = heap.top();
		heap.pop();
		
		long long v = t.second,dist = t.first;
		if(st[v])continue;
		
		st[v] = true;
		
		for(int i = h[v];i != -1;i = ne[i]){
			int j = e[i];
			if(d[j] > dist + w[i]){
				d[j] = dist+w[i];
				heap.push({d[j],j});
			}
		}
	}
}
void bfs(int S){
	memset(d,0x3f,sizeof(d));
//	memset(st,false,sizeof(st));
	
	queue<int> q;
	q.push(S);
//	st[S] = true;
	d[S] = 0;
	
	while(!q.empty()){
		int t = q.front();
		q.pop();
		
		for(int i = h[t];i != -1;i = ne[i]){
			int j = e[i];
			if(d[j] > d[t] + w[i]){
				d[j] = d[t] + w[i];
//				if(!st[j]){
					q.push(j);
//					st[j] = true;
//				}
			}
		}
	}
}
long long g[666][666];
void dijkstra2(int S,long long d[666]){
	memset(d,0x3f,sizeof(d));
	memset(st,false,sizeof(st));
	priority_queue<PII,vector<PII>,greater<PII> > heap;
	d[S] = 0;
	st[S] = 0;
	heap.push({0,S});
	
	while(!heap.empty()){
		PII t = heap.top();
		heap.pop();
		
		long long v = t.second,dist = t.first;
		if(st[v])continue;
		
		st[v] = true;
		
		for(int i = h[v];i != -1;i = ne[i]){
			int j = e[i];
			if(d[j] > dist + w[i]){
				d[j] = dist+w[i];
				heap.push({d[j],j});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cout << sizeof(a)/1024/1024 << '\n';
	c = read(),n = read(),m = read(),most = read(),q = read();
//	cout << c << '\n';
//	scanf("%d%d%d%d%d",&c,&n,&m,&most,&q);
	init();
	for(int i = 1;i <= m;i++){
//		scanf("%lld",&cost[i]);
		cost[i] = read();
	}
	
	if(9 <= c && c <= 11){
		int k;
		for(int i = 1;i <= n;i++){
	//		scanf("%d",&k);
			k = read();
			int a1,a2,t1,t2;
			a1 = read(),t1 = read();
			a2 = read(),t2 = read();
			add(a1,a2,t1+t2);
			add(a2,a1,t1+t2);
		}
		for(int i = 1;i <= 600;i++){
			dijkstra2(i,g[i]);
		}
		
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			cout << cost[x]+cost[y] + g[x][y] << '\n';
		}
		
		return 0;
	}
	
	if(12 <= c && c <= 15){
		int k;
		for(int i = 1;i <= n;i++){
	//		scanf("%d",&k);
			k = read();
			int a,t;
			for(int j = 1;j <= k;j++){
	//			scanf("%d%d",&a,&t);
				a = read(),t = read();
				add(n+a,i,t);
				add(i,n+a,t);
			}
		}
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			bfs(x+n);
//			for(int i = 1;i <= m+n;i++){
//				cout << d[i] << ' ';
//			}
//			cout << '\n';
			printf("%lld\n",d[y+n]+cost[x]+cost[y]) << '\n';
		}
		return 0;
	}
	
	int k;
	for(int i = 1;i <= n;i++){
//		scanf("%d",&k);
		k = read();
		int a,t;
		for(int j = 1;j <= k;j++){
//			scanf("%d%d",&a,&t);
			a = read(),t = read();
			add(n+a,i,t);
			add(i,n+a,t);
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		dijkstra(x+n);
		cout << d[y+n]+cost[x]+cost[y] << '\n';
	}
	return 0;
}
