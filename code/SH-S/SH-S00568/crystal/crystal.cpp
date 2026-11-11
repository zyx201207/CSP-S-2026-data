#include<bits/stdc++.h>
#define io ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N = 5e5 + 10;
long long a[N];
int main(){
	io;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long ans = 0;
	long long cnt = 0;
	long long op = 0;
	for(int i = 1; i <= n; i ++){
		op += cnt * (a[i] - a[i - 1]);
		cnt ++;
		while(op > m){
			cnt --;
			op -= (a[i] - a[i - cnt]);
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}
