#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	int a[200005];
	int maxn = INT_MIN;
	int sum;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n == m){
		sum = a[1];
		for(int i = 2; i <= n; i++){
			sum &= a[i];
		}
		cout << sum;
		return 0;
	}
	for(int i = 1; i <= n - m + 1; i++){
		for(int j = i + 1; j <= n; j++){
			sum = a[i];
			j -= m - 2;
			for(int o = 1; o <= m - 1; o++){
				sum &= a[j++];
			}
			if(sum > maxn){
				maxn = sum;
			}
		}
	}cout << maxn;
	return 0; 
} 
