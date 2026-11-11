#include<bits/stdc++.h>
using namespace std;
long long n, d, a[2000006], ans, minn, sum;
void dfs(long long x, long long y, long long num){
	if(x == y){
		if(num < minn){
			minn = num;
			ans = 1;
		}
		if(num == minn){
			ans ++;
		}
		return;
	}
	int i = x;
	while(1){ 
		i ++;
		if(a[i]<= a[y] && a[i] <= a[x] + d){
			cout << x << " " << y << " ";
			dfs(i, y, num + 1);
		}
		else{
			break;
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t --){
		cin >> n >> d;
		memset(a, 1, sizeof(a));
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
		}
		sum = 0;
		for(int i = 1; i < n; i ++){
			ans = 0, minn = 1e18;
			for(int j = i + 3; j <= n; j ++){
				dfs(i, j, 1);
			}
			if(ans == 2) sum ++;
		}
		cout << sum << endl;
	}
	return 0;
}

