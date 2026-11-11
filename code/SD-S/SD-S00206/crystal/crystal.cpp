#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 5e5 + 7;
int n, ans;
ll m, a[N];

void Solve(){
	cin >> n >> m;
	for(int k = 1; k <= n; k++)
		cin >> a[k];
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; ){
		ll less = m - (a[i] - a[i - 1]);
		int l = i - 1, now = 1, r = i + 1;
		while(l >= 1 && less >= 0){
			now++;
			less -= a[i] - a[l - 1];
			l--;
		}
		while(r <= n && a[r] == a[i]){
			now++; 
			r++;
		}
		ans = max(ans, now);
		i = r;
	}
	cout << ans;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;//cin >> T;
	while(T--)
		Solve();
	return 0;
}

