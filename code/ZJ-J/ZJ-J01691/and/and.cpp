#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, k;
int a[N];
int dfs(int b, int s, int ans){
	if(s == k) return ans;
	int sum = -INT_MAX;
	for(int i = b + 1;i <= n - k + s;i++){
		sum = max(sum, dfs(i, s + 1, ans & a[i]));
	}
	return sum;
}
int q(){
	int sum = -INT_MAX;
	for(int i = 1;i <= n - k;i++){
		sum = max(sum, dfs(i, 1, a[i]));
	}
	return sum;
}
int main(){
	freopen("and.in", "w", stdin);
	freopen("and.out", "r", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	cout << q();
	return 0;
}
