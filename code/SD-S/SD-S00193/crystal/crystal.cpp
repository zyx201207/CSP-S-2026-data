#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N];
int n,m;
bool check(int x){
	int ans = 0;
	for(int i = 1;i <= x;i++){
		ans += (a[x] - a[i]);
	}
	return ans <= m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	int sum = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];sum += a[i];
	}
//	if(sum == 0){
//		sort(a + 1,a + n + 1);
//		int mid = (1 + n) / 2;
//		int sum = 0;
//		for(int i = mid - 1,j = mid + 1;i >= 1,j <= n;i--,j++){
//			sum = sum + a[i] + a[j]; 
//			if(sum > m){
//				i++;j--;
//				cout << (mid - i) + (j - mid) + 1;
//				return 0;
//			}
//		}
//	}
	sort(a + 1,a + n + 1);
	int l = 1,r = n;
	int ans = 0;
	int k;
	while(l <= r){
		int mid = (l + r) / 2;
		if(l == k){
			cout << mid;
			return 0;
		}
//		cout << mid << endl;
		if(check(mid)){
			k = l;
			l = mid;
			//cout << l << endl;
			ans = l;
		}
		else{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
} 
