#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n, m;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll ans = 0, ind = 1, sum = 0;
	for(int i = 1;i <= n;i++){
		sum += (a[i] - a[i - 1]) * (i - ind);
		while(ind <= i && sum > m){
			sum -= a[i] - a[ind];
			ind++;
		}
		ans = max(i - ind + 1, ans);
	}
	cout << ans;
	return 1;
}
