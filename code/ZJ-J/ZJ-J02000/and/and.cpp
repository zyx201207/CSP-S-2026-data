#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1, cmp);
	long long ans = 0;
	for(int i = 1; i < m; i++){
		ans = a[i] & a[i+1];
	}
	cout << ans;
	return 0;
}