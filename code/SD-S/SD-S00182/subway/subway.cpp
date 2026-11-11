#include<bits/stdc++.h>
using namespace std;
int n, m, d, o;
int w[500050];
//typedef struct _SUBWAY_{
//	int p, t;
//}sub;
struct node{
	
	int v;
	long long w;
	bool operator< (const node &b) const{
		return this->w < b.w; 
	}
	bool cmp(node a, node b){
		return a.w < b.w;
	}
};
int p[500010], t[500010];
long long dis[510000];
priority_queue<node, vector<node>, less<node> > q[510];
node st[5000100];
int itop;
inline long long read(){
	long long x(0);
	int f(1);
	char c(getchar());
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline void write(long long x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c(read()), k(0);
	n = read(), m = read(), d = read(), o = read();
	for(int i = 1; i <= m; ++i) w[i] = read();
	for(int i = 1; i <= n; ++i){
		k = read();
		for(int j = 1; j <= k; ++j){
			p[j] = read(), t[j] = read();
		}
		for(int a = 1; a <= k; ++a){
			for(int b = a + 1; b <= k; ++b){
				q[p[a]].push({p[b], t[a]+t[b]});
				q[p[b]].push({p[a], t[a]+t[b]});
			}
		}
	}
	
	int x(0), y(0);
	int e, s;
	for(int i = 1; i <= o; ++i){
		x = read(), y = read();
		if(x > y) swap(x, y);
		memset(dis, 0x3f3f3f3f, sizeof(dis));
		dis[x] = 0;
		for(int j = 1; j <= m; ++j){
			while(!q[j].empty()){
				e = q[j].top().v, s = q[j].top().w;
				q[j].pop();
				if(dis[e] > dis[j] + s){
					dis[e] = dis[j] + s;
					q[e].push({j, s});
				}
				st[++itop] = {e, s};
			}
			while(itop > 0){
				q[j].push({st[itop].v, st[itop].w});
				itop--;
			}
		}
		write(dis[y] + w[x] + w[y]);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

