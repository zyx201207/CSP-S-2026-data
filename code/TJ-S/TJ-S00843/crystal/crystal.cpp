#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5; 
int n;
ll m;
ll a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 1, l = 1;
	int z = 0;
	for(int i = 2;i <= n;i++){
		z += (a[i] - a[i - 1]) * (i - l);
		while(z > m){
			z -= a[i] - a[l];
			l ++;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}

