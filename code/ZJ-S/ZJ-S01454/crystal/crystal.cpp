#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read() {
	ll res = 0, neg = 1; char ch = getchar();
	while(ch<'0' or ch>'9') { if(ch == '-') neg = -1; ch = getchar(); }
	while(ch>='0' and ch<='9') res = res*10 + ch-'0', ch = getchar();
	return res * neg;
}

void write(ll x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x+'0');
	else write(x/10), putchar(x%10+'0');
}

const int N = 5e5+10;

int n; ll m;
ll a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read(), m = read();
	for(int i=1; i<=n; i++) a[i] = read();
	
	sort(a+1, a+1+n);
	for(int i=1; i<=n; i++) s[i] = s[i-1] + a[i];
	
	int ans = 0;
	
	for(int i=1, j=1; i<=n; i++) {
		ll val = 1ll*(i-j+1) * a[i] - (s[i]-s[j-1]);
		while(val > m) {
			j++;
			val = (i-j+1) * a[i] - (s[i]-s[j-1]); 
		}
		
		ans = max(ans, i-j+1);
	}
	
	write(ans); puts("");
	
	return 0;
}
