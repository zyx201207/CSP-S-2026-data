#include<bits/stdc++.h>
using namespace std;
inline long long read();
int c, n, m, d, q;
int num = INT_MAX;
int w[500005];
int l[505][500005], t[505][500005];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i ++){
		w[i] = read();
	}
	for(int i = 1; i <= n; i ++){
		int num; cin >> num;
		for(int j = 1; j <= num; j ++){
			int x, y; cin >> x >> y;
		}
	}
	while(q --){
		int x, y; cin >> x >> y;
		int ans = w[x] + w[y];
        cout << ans << '\n';
	}
	return 0;
}
inline long long read(){
	long long f = 0, s = 1; char c = getchar();
	while(!isdigit(c)){
		if(c == '-')	s = -1;
		c = getchar();
	}
	while(isdigit(c)){
		f = (f << 3) + (f << 1) + (c ^ 48);
		c = getchar();
	}
	return f * s;
}