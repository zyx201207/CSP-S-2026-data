#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 9;
int n, m;
int arr[N];
bool check(int x){
	int lst = 0;
	for(int i = 1; i <= x; i++) lst += arr[x] - arr[i];
	if(lst <= m) return 1;
	for(int l = 2; l + x - 1 <= n; l++){
		int r = l + x - 1;
		lst = lst - (arr[r - 1] - arr[l - 1]) + (x - 1) * (arr[r] - arr[l]);
		if(lst <= m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + 1 + n);
	int l = 1, r = n, mid, ans = 0;
	while(l <= r){
		mid = l + r + 1 >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
