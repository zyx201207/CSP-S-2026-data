#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N], pre[N];

signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	
	//A B
	bool has = 1;
	int sum = a[2] - a[1];
	for(int i = 3; i <= n; i++){
		if(a[i] - a[i - 1] != sum){
			has = 0;
			break;
		}
	}
	int cur = sum;
	int an = 0;
	if(has){
		while(a[n] > 0){
			if(a[n] - cur >= 0){
				a[n] -= cur;
				cur += sum;
				an++;
			}else{
				break;
			}
		}
		cout << an;
		return 0;
	}
	
	int res = 0;
	for(int i = 1; i <= n; i++){
		int x = m,ans = 0;
		for(int j = i; j >= 1; j--){
			int cnt = a[i] - a[j];
			if(x - cnt >= 0){
				ans++;
				x -= cnt;
			}else{
				break;
			}
		}
		res = max(res, ans);
	}
	cout << res;
	return 0;
}
/*

*/