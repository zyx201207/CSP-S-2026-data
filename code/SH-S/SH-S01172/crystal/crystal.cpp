#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5e5 + 20;
long long arr[MAXN] = {};
long long n, k, ans = 0;
//int moveuse(int start, int end){
//	long long sum = 0;
//	for(int i = end; i >= start; i--){
//		sum += (arr[end] - arr[i]);
//	}
//	return sum;
//}
void f(int start, int end, long long move){
	int len = end - start + 1;
	long long nextc = (long long)move + (arr[end + 1] - arr[end]) * len;
	long long backc = (long long)move - arr[end] + arr[start];
	//cout << move << ' ' << start << ' ' << end << endl;
	if(start > end and start < n){
		f(start, start, 0);
		return;
	}
	if(end > n) return;
	ans = max(len, (int)ans);
	if(nextc <= k){
		if(end == n) return;
		f(start, end + 1, (long long)nextc);
		return;
	} else{
		f(start + 1, end, (long long)backc);
		return;
	}
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	f(1, 1, 0);
	cout << ans;
} 


