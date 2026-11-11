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

int n;
ll a[200005], ans, L;
string c;

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		char ch;
		cin >> a[i];
		cin >> ch;
		for(int j = 1; j <= a[i]; ++j) c += ch;
		L += a[i];
	}
	for(int i = 0; i <= L / 2 - 1; ++i) {
		if(c[i] != c[L - 1 - i]) ++ans;
	}
	cout << ans;
	
	return 0;
}

