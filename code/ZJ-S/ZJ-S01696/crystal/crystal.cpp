#include<bits/stdc++.h>
#define ll long long
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)

int n;
ll m, a[500005];
ll c[500005];
int L, R, mid, p;
ll minu;
int Ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	std::cin >> n >> m;
	for(int i = 1; i <= n; i ++) std::cin >> a[i];
	std::sort(a + 1, a + 1 + n);
	
	for(int i = 1; i <= n; i ++) c[i] = a[n] - a[i], c[i] += c[i - 1];
	for(int i = n; i >= 1; i --) {
		minu = a[n] - a[i];
		L = 1, R = i, p = i;
		while(L <= R) {
			mid = L + R >> 1;
			if(c[i] - c[mid - 1] - minu * (i - mid + 1) > m) L = mid + 1;
			else p = mid, R = mid - 1;
		}
		Ans = max(i - p + 1, Ans);
	}
	
	std::cout << Ans;
	return 0;
}
