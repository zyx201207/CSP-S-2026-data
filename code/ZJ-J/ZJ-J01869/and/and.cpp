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
const int N = 200100;
int n, m, a[N];
int cmp(int x, int y){
	return x > y;
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + 1 + n, cmp);
	int ans = a[1];
	for(int i = 2; i <= m; i++){
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}
//lzy1219nb
//lzy1219是我爹