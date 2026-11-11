#include <bits/stdc++.h>
using namespace std;
long long cha[500005], d1[500005], d2[500005], a[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if (i > 0){
			cha[i] = a[i] - a[i - 1];
		}
	}
	for(int i = n - 1; i >= 1; i--){
		d1[n - i] = cha[i] + d1[n - i - 1]; 
	}
	for(int i = n - 2; i >= 0; i--){
		d2[i] = d2[i + 1] + d1[n - i - 1];
	}
	int l = 0, r = n - 1;
	long long sum = d2[0];
	while(sum > m){
		if (d2[l] - d2[l + 1] < (d2[r - 1] - d2[r]) * (r - l)){
			sum -= (d2[r - 1] - d2[r]) * (r - l);
			r--;
		}else{
			sum -= d2[l] - d2[l + 1];
			l++;
		}
		if (l + 2 <= r - 2){
			
		}
	}
	cout << r - l + 1;
	return 0;
}