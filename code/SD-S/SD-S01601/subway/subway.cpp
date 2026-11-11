#include<bits/stdc++.h>
#define ll long long
#define mkp(x,y) make_pair((x),(y))
using namespace std;
typedef pair<int,int> PII;
const int N = 505;
const int M = 5e5+5;
int c,n,m,d,q;
ll g[N][N],w[M];
int cnt[M];
PII line[M][21];
ll read(){
	char c = getchar();
	ll res = 0;
	int f = 1;
	while(c < '0' || c > '9'){
		if(c == '-')	f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		res = res*10+(int)(c-'0');
		c = getchar();
	}
	return f*res;
}
void write(ll num){
	if(num < 0){
		putchar('-');
		num = -num;
	}
	if(num >= 10)
		write(num/10);
	putchar(num%10 + '0');
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof g);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for(int i = 1;i <= m;++i)
		w[i] = read();
	for(int i = 1;i <= n;++i){
		g[i][i] = 0;
		int k;
		k = read();
		for(int j = 1;j <= k;++j){
			int a,t;
			a = read();
			t = read();
			line[a][++cnt[a]] = mkp(i,t);
//			printf("%d %d %d\n",a,cnt[a],i);
		}
	}
	for(int i = 1;i <= m;++i){
		for(int j = 1;j <= cnt[i];++j){
			for(int k = j+1;k <= cnt[i];++k){
				int s = line[i][j].first;
				int t = line[i][k].first;
				g[t][s] = g[s][t] = min(g[s][t],(ll)line[i][j].second + line[i][k].second);
			}
		}
	}
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= n;++j)
			for(int k = 1;k <= n;++k)
				g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
	while(--q){
		int s,t;
		s = read();
		t = read();
		ll res = -1;
		for(int i = 1;i <= cnt[s];++i){
			for(int j = 1;j <= cnt[t];++j){
				int x = line[s][i].first;
				int y = line[t][j].first;
				ll calc = g[x][y]+line[s][i].second+line[t][j].second;
				if(res == -1)	res = calc;
				res = min(res,calc);
			}
		}
		write(w[s]+w[t]+res);
		putchar('\n');
	}
	return 0;
}
