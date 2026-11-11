#include <bits/stdc++.h>
#define go(i,l,r) for(int i = l; i <= r; i++)
#define re(i,r,l) for(int i = r; i >= l; i--)
using namespace std;
using ll = long long;

const int N = 5e5+5;
int n, ans;
ll m, a[N], s[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	go(i,1,n) cin >> a[i];
	
	sort(a+1, a+1+n);
	go(i,1,n) s[i] = s[i-1] + a[i];
	
	int p = 1;
	go(i,1,n){
		while((i-p+1) * a[i] - s[i] + s[p-1] > m) p ++;
		ans = max(ans, i-p+1);
	}
	cout << ans;
	return 0;
}
