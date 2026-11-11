#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
const int N = 500010;
int n, m, a[N], b[N], t[N], t2[N];
signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = read(), m = read();
	int f = 1;
	for(int i = 1; i <= n; i++){
		a[i] = read();
		if(a[i] < a[i - 1]) f = 0;
	}
	if(f){
		int sum = 0;
		a[0] = a[1];
		for(int i = 1; i <= n + 1; i++){
			if(a[i] != a[i - 1]){
				cout << sum << ' ';
				sum = i;
			}else sum += i;
		}
		return 0;
	}else{
		for(int i = 1; i <= n; i++){
			int cnt = 0;
			for(int j = 1; j <= n; j++)
				b[j] = 0;
			for(int j = i; j <= n; j++){
				if(!t[a[j]]) t[a[j]]++, b[++cnt] = a[j];
				else{
					int k = cnt - 1;
					while(b[k] != a[j]) t[b[k]]--, k--;
					cnt = k;
				}
			}
			for(int j = 1; j <= m; j++)
				t2[j] += t[j], t[j] = 0;
		}
		for(int j = 1; j <= m; j++)
			cout << t2[j] << ' ';
	}
	return 0;
}
//lzy1219nb
//lzy1219是我爹
//happy AFO!