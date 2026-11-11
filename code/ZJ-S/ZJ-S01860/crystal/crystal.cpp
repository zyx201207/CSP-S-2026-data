#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int MAXN = 5e5 + 5;
int n, ans = 1;
ll a[MAXN], s[MAXN], m;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	int l = 1;
	for(int r = 2; r <= n; r++){
		while(a[r] * (r - l + 1) - (s[r] - s[l - 1]) > m){
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
