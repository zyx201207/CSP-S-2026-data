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

int n, m, a[500005], cnt[300005], pos[300005];

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i <= n; ++i) cnt[i] = i;
	for(int i = 1; i <= n; ++i) {
//		memset(pos, 0, sizeof(pos));
		for(int j = i; j <= n; ++j) {
			if(pos[a[j]]) {
				for(int k = pos[a[j]]; k < j; ++k) {
					--cnt[a[k]];
				}
			} else pos[a[j]] = j;
		}
	}
	for(int i = 1; i <= m; ++i) printf("%d ", cnt[i] % (rand() | 1));
	
	return 0;
}

//#include <bits/stdc++.h>
//#define ll long long
//#define fir first
//#define sec second
//#define pb push_back
//#define pii pair<int, int>
//#define pque priority_queue
//#define umap unordered_map
//
//using namespace std;
//
//inline int read()
//{
//	int x = 0, f = 1;
//	char ch = getchar();
//	while(ch < '0' || ch > '9') {
//		if(ch == '-') f = -1;
//		ch = getchar();
//	}
//	while(ch >= '0' && ch <= '9') {
//		x = (x << 1) + (x << 3) + (ch - '0');
//		ch = getchar();
//	}
//	return x * f;
//}
//
//void write(int x)
//{
//	if(x < 0) putchar('-'), x = -x;
//	if(x > 9) write(x / 10);
//	putchar((char)(x % 10 + '0'));
//}
//
//int n, m, a[500005], cnt[300005], pos[300005];
//
//signed main()
//{
//	freopen("card.in", "r", stdin);
//	freopen("card.out", "w", stdout);
//	//ios::sync_with_stdio(false);
//	//cin.tie(0);
//	//cout.tie(0);
//	
//	scanf("%d%d", &n, &m);
//	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
//	for(int i = 1; i <= m; ++i) cout << i << ' ';
//	
//	return 0;
//}


