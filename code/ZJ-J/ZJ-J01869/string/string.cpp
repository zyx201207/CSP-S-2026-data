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
int a[N], a2[N], b[N], b2[N], n, ans;
char c[N], c2[N];
signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n = read();
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	for(int i = 1; i <= n; i++){
		c2[i] = c[n - i + 1];
		a2[i] = a[n - i + 1];
		b[i] = b[i - 1] + a[i];
		b2[i] = b2[i - 1] + a2[i];
	}//l/r --> 第l/r个字母
	int mid = b[n] / 2, l = 1, r = 0, f = 0;
	int i = 1, j = 1;
	while(r < mid){
		if(c[i] != c2[j]) f = 1;
		else f = 0;
		if(b[i] > b2[j]){
			r = b2[j];
			j++;
		}else{
			r = b[i];
			i++;
		}
		r = min(r, mid);
		ans += (r - l + 1) * f;
		l = r + 1;
	}
	cout << ans;
	return 0;
}
//lzy1219nb
//lzy1219是我爹