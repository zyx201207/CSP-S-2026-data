#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n;
long long m;
long long ans;
long long sum;
long long a[N];
long long s[N];
bool check(int x, int y){
	//求x到y的总距离
	long long len = y - x + 1;
	long long res = len * a[y] - s[y] + s[x - 1];
	return res <= m;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++){
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i ++){
		long long l = 1;
		long long r = i;
		long long cnt = 0;
		while(l <= r){
			long long mid = (l + r) / 2;
			if(check(mid, i)){
				cnt = mid;
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		ans = max(ans, i - cnt + 1);
	}
	cout << ans;
	return 0;
}


