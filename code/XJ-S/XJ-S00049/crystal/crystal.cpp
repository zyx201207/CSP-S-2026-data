#include<bits/stdc++.h> 
using namespace std;
long long n, m, a[5000005], b[5000005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	int t = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
			t = 0;
		}
	}
	if(t){
		int sum = 0, i;
		for(i = 2; i <= n; i++){
			sum = i;
			for(int j = 1; j <= i - 1; j++){
				m -= (a[i] - a[i - 1]);
				if(m < 0){
					sum -= (i - 1 - j);
					sum += 1;
					break;
				}
			}
		}
		cout << sum << "\n";
		return 0;
	}
	for(int i = 1; i <= n; i++){
		b[a[i]]++;
	}
	int flag = 0, sum = 0;
	for(int i = 1; i <= 10000000; i++){
		if(b[i] && flag){
			int q = 0;
			for(int j = 1; j <= b[flag]; j++){
				m -= (i - flag);
				if(m < 0){
					q = 1;
					break;
				}
				sum++;
			}
			sum += b[i];
			if(q){
				cout << sum << "\n";
				return 0;
			}
		}else if(b[i] && !flag){
			flag = i;
		}
	}
	return 0;
}
