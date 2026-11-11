#include<bits/stdc++.h>
using namespace std;
int a[200001];
char c[200001];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	long long sum = 0;
	while(l < r){
		if(c[l] != c[r]){
			if(a[l] > a[r]){
				a[l] -= a[r];
				sum += a[r];
				a[r] = 0;
				r--;
			}else{
				a[r] -= a[l];
				sum += a[l];
				a[l] = 0;
				l++;
			}
		}else{
			if(a[l] > a[r]){
				a[l] -= a[r];
				a[r] = 0;
				r--;
			}else{
				a[r] -= a[l];
				a[l] = 0;
				l++;
			}
		}
	}
	cout << sum;
	return 0;
}
