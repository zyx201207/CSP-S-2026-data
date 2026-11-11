#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n, m;
int f1, f2;
int ans;
int s[5];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
		if(a[i] > 4)f1 = 1;
		if(a[i] != i-1)f2 = 1;
	}
	
	if(m == 1){
		for(int i = 1 ; i <= n ; i++)ans = max(ans, a[i]);
		cout << ans;
		return 0;
	}
	if(m == 2){
		for(int i = 1 ; i < n ; i++)for(int j = i + 1 ; j <= n ; j++)ans = max(ans, (a[i] & a[j]));
		cout << ans;
		return 0;
	}
	if(m == n){
		ans = a[1];
		for(int i = 1 ; i <= n ; i++)ans = (ans & a[i]);
		cout << ans;
		return 0;
	}
	
	if(n <= 20){
		int sum = 1;
		for(int i = 1 ; i <= n ; i++)sum *= 2;
		for(int i = 1 ; i <= sum - 1 ; i++){
			int k = 0;
			int x = i;
			int y = 0;
			int t = 0;
			while(x > 0){
				t++;
				if(x % 2 == 1){
					k++;
					if(k == 1)y = a[t];
					else y = (y & a[t]);
				}
				x /= 2;
				if(k > m)break;
			}
			if(k == m)ans = max(ans, y);
		}
		cout << ans;
		return 0;
	}
	
	if(f1 == 0){
		for(int i = 1 ; i <= n ; i++)s[a[i]]++;
		if(s[4] >= m){
			cout << 4;
			return 0;
		}
		if(s[3] >= m){
			cout << 3;
			return 0;
		}
		if(s[3] + s[2] >= m){
			cout << 2;
			return 0;
		}
		if(s[3] + s[1] >= m){
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0;
	}    
	
	if(f2 == 0){
		int ans = n - 1;
		for(int i = 1 ; i < m ; i++){
			ans = (ans - 1) / 2;
		}
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}
