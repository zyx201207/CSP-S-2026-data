#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510,M = 500010;
const ll INF = 1e16;
int c,n,m,d,q;
int w[M];
struct edge{int v,w;};
vector<edge> e[M];
ll f[N][N];
bool vis[N][N];
#define gc getchar
int read_int(){
	int val = 0,w = 1;
	char c = gc();
	while(c<'0'||c>'9'){
		if(c=='-') w = -1;
		c = gc();
	}
	while('0'<=c&&c<='9'){
		val = val*10+c-'0';
		c = gc();
	}
	return val*w;
}
void write_ll(ll x){
	static int a[60],top;
	top = 0;
	if(x<0){
		putchar('-');
		x = -x; 
	}
	do{
		a[++top] = x%10;
		x /= 10;
	}while(x);
	while(top) putchar('0'+a[top--]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) w[i] = read_int();
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		for(int j = 1;j <= k;j++){
			int v,w;
			v = read_int();
			w = read_int();
			e[v].push_back({i,w});
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			f[i][j] = INF;
		}
		f[i][i] = 0;
	}
	for(int i = 1;i <= m;i++){
		for(int x = 0;x < e[i].size();x++){
			int v1 = e[i][x].v;ll w1 = e[i][x].w;
			for(int y = x+1;y < e[i].size();y++){
				int v2 = e[i][y].v;ll w2 = e[i][y].w;
				f[v1][v2] = f[v2][v1] = min(f[v1][v2],w1+w2);
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		u = read_int();
		v = read_int();
		ll ans = INF;
		for(int x = 0;x < e[u].size();x++){
			int v1 = e[u][x].v;ll w1 = e[u][x].w;
			for(int y = 0;y < e[v].size();y++){
				int v2 = e[v][y].v;ll w2 = e[v][y].w;
				ans = min(ans,w[u]+w1+f[v1][v2]+w2+w[v]);
			}
		}
		write_ll(ans);
		putchar('\n');
	}
}
