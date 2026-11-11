#include<iostream>
#include<stdio.h>
#include<vector>
#define ll long long
#define INF (ll)0x3f3f3f3f3f3f3f3f
using namespace std;

struct st{
	int x;
	ll y;
};

int c, n, m, d, q;
ll w[600000];
int k[600];
vector< vector<st> > a(600000, vector<st>(0, (st{0, 0})));//a [i] : station i, a[i][j] : sta i -> line x, take y(time)
ll g[600][600];// g[i][j] = time from line i to line j

void Frd(ll &num){
	num = 0;
	char c = '&';
	while(c < '0' || c > '9'){
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		num = 10 * num + (c - '0');
		c = getchar();
	}
	return;
}

void Frd(int &num){
	num = 0;
	char c = '&';
	while(c < '0' || c > '9'){
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		num = 10 * num + (c - '0');
		c = getchar();
	}
	return;
}

int main(){
	int i, j, p;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	//scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	//cin >> c >> n >> m >> d >> q;
	Frd(c);
	Frd(n);
	Frd(m);
	Frd(d);
	Frd(q);
	for(i = 1; i <= m; i++){
		//scanf("%lld", w[i]);
		Frd(w[i]);
	}
	st o;
	int oo;
	for(i = 1; i <= n; i++){
		//scanf("%d", &(k[i]));
		Frd(k[i]);
		o.x = i;
		for(j = 1; j <= k[i]; j++){
			Frd(oo);
			Frd(o.y);
			a[oo].push_back(o);
		}
	}
	//
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(i == j){
				g[i][j] = 0;
			}else{
				g[i][j] = INF;
			}
		}
	}
	//
	for(i = 1; i <= m; i++){
		for(j = 0; j < a[i].size(); j++){
			for(p = j + 1; p < a[i].size(); p++){
				g[a[i][j].x][a[i][p].x] = min(g[a[i][j].x][a[i][p].x], a[i][j].y + a[i][p].y);
				g[a[i][p].x][a[i][j].x] = g[a[i][j].x][a[i][p].x];
			}
		}
	}
	//and floyd g
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			for(p = 1; p <= n; p++){
				g[i][j] = min(g[i][j], g[i][p] + g[j][p]);
				g[j][i] = g[i][j];
			}
		}
	}
	/*
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			cout << g[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	int xx, yy;//for each q
	ll ans;
	for(i = 1; i <= q; i++){
		cin >> xx >> yy;
		if(xx == yy){
			printf("0\n");
			continue;
		}
		ans = INF;
		for(j = 0; j < a[xx].size(); j++){
			for(p = 0; p < a[yy].size(); p++){
				ans = min(ans, g[a[xx][j].x][a[yy][p].x] + a[xx][j].y + a[yy][p].y);
			}
		}
		ans += w[xx] + w[yy];
		printf("%lld\n", ans);
	}
	//rp += INF!
	
	return 0;
}

//XX X XXX
//now 16:31, probably end of t2
//ohhyeah i did it
//t2 is a simple floyd
//and fast read/out, however, took 30min
//why???
//why cant i use stdio(scanf, printf
//nooo running out of time
