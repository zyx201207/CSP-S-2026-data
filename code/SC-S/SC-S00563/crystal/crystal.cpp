#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x * 10) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

void write(int x){
	if(x < 0){putchar('-');x = -x;}
	if(x > 9)write(x / 10);
	putchar(x % 10 + '0');
}

const int N = 5e5 + 5;
int n, m, a[N], d[N], s[N], ans;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	n = read(); m = read();
	for(int i = 1;i <= n;i ++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	ans = 0;
	for(int i = 1;i <= n;i ++){
		d[i] = a[i] - a[i - 1];
		s[i] = s[i - 1] + i * d[i];
		int l = 0, r = i;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			int sum = s[i] - s[mid] - (int)mid * (a[i] - a[mid]);
			if(sum <= m) r = mid;
			else l = mid;
		}
		ans = max(ans, i - r + 1);
	}
	write(ans);
	return 0;
}