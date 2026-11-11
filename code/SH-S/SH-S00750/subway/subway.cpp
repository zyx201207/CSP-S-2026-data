#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAXM = 5e5 + 5, MAXN = 505;
const long long INF = 1e18;
int c, n, m, D, q;
long long ans, w[MAXM];
int cntedge;
vector<pair<int, long long> > plt[MAXM];
long long e[MAXN][MAXN], d[MAXN][MAXN];
template<typename T> inline void readint(T &x){
	char ch = getchar();
	bool neg = 0;
	x = 0;
	while(ch < '0' || ch > '9'){
		if(ch == '-')neg = 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	if(neg)x = -x;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(d, 0x3f, sizeof(d));
	readint(c);
	readint(n);
	readint(m);
	readint(D);
	readint(q);
	for(int i = 1;i <= m;i++){
		readint(w[i]);
	}
	for(int i = 1;i <= n;i++){
		d[i][i] = 0;
		int k, ai;
		long long ti;
		readint(k);
		for(int j = 1;j <= k;j++){
			readint(ai);
			readint(ti);
			plt[ai].push_back(make_pair(i, ti));
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < plt[i].size();j++){
			for(int k = j + 1;k < plt[i].size();k++){
				d[plt[i][j].first][plt[i][k].first] = min(d[plt[i][j].first][plt[i][k].first], plt[i][j].second + plt[i][k].second);
				d[plt[i][k].first][plt[i][j].first] = min(d[plt[i][k].first][plt[i][j].first], plt[i][j].second + plt[i][k].second);
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(d[i][k] < INF && d[k][j] < INF){
				    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				    d[j][i] = min(d[j][i], d[i][k] + d[k][j]);
				}
			}
		}
	}
	int st, ed;
	while(q--){
		readint(st);
		readint(ed);
		ans = INF;
		//printf("Calculating for station %d to %d\n", st, ed);
		for(int i = 0;i < plt[st].size();i++){
			for(int j = 0;j < plt[ed].size();j++){
				//printf("This incurs a cost of %lld\n", w[st] + w[ed] + plt[st][i].second + plt[ed][j].second + d[plt[st][i].first][plt[ed][j].first]);
				ans = min(ans, w[st] + w[ed] + plt[st][i].second + plt[ed][j].second + d[plt[st][i].first][plt[ed][j].first]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
