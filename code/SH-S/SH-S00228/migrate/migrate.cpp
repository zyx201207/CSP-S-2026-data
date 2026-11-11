#include<bits/stdc++.h>
using namespace std;
int arr[2000009];
void solveA(){

	int n, d;
	cin >> n >> d;
	int cnt = 0;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	int t = d / (arr[2] - arr[1]);
	if(t == 0){
		cout << 0 << endl;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(n / t == 1 && n % t) cnt += n - i + 1;
	}
	cout << cnt << endl;
	return;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	if(c >= 11 && c <= 12){
		while(t--) solveA();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
