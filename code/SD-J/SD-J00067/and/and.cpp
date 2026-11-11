#include <bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pb push_back
#define pii pair<int, int>
#define pque priority_queue
#define umap unordered_map

using namespace std;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

void write(int x)
{
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar((char)(x % 10 + '0'));
}

int n, a[200005], m, ans;
int choi[200005], len;

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	
	for(int j = 30; j >= 0; --j) {
		int cnt = 0;
		if(!len) {
			for(int i = 1; i <= n; ++i) 
				if((1 << j) & a[i]) choi[++cnt] = i;
		} else {
			for(int i = 1; i <= len; ++i) {
				if((1 << j) & a[choi[i]]) ++cnt;
			}
			if(cnt < m) continue;
			cnt = 0;
			for(int i = 1; i <= len; ++i) {
				if((1 << j) & a[choi[i]]) choi[++cnt] = choi[i];
			}
			len = cnt;
			ans += (1 << j);
			continue;
		}
			
		if(cnt >= m) {
			ans += (1 << j);
			len = cnt;
		}
	}
	printf("%d", ans);
	
	return 0;
}

