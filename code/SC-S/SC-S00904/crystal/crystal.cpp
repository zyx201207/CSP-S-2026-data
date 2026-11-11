#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 10;
int n, m, pos;
int a[maxn];
bool check(int x){
	int sum = 0;
	for(int i = 1; i <= n; i++){
		if(x - a[i] < 0){
			pos = i - 1;
			break;
		}
		sum += x - a[i];
	}
	return sum <= m;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int cnta = 0, cntb = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == i){
			cnta++;
		}
		if(i > 2){
			if(a[i] - a[i - 1] == a[i - 1] - a[i - 2]){
				cntb++;
			}
		}
	}
	if(cnta == n){//A
		int sum = 0, ans = 0;
		for(int i = 1; i <= n; i++){
			sum += i;
			ans++;
			if(sum > m){
				break;
			}
		}
		cout << ans;
		return 0;
	}
	if(cntb == n - 2){//B
		int sum = 0, ans = 0;
		for(int i = 1; i <= n; i++){
			sum += i;
			ans++;
			sum *= 2;
			if(sum > m){
				break;
			}
		}
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = n, p = -1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)){
			l = mid + 1;
			p = max(p, pos);
		}else{
			r = mid - 1;
		}
	}
	cout << p;
	return 0;
}