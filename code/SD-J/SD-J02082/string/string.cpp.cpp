#include<bits/stdc++.h>
using namespace std;
int n, a[200005], sum;
char c[200005];
string s;
int hw(){
	int cnt=0, b = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= a[i]; j++){
			s[b] = c[i];
			b++;
		}
	}
	for (int i = 0; i < sum/2; i++){
		if (s[i] != s[sum-i-1]){
			cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("string.in", "r",stdin);
	freopen("string.out", "w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	
	long long cnt=0, b = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= a[i]; j++){
			s[b] = c[i];
			b++;
		}
	}
	for (long long i = 0; i < sum/2; i++){
		if (s[i] != s[sum-i-1]){
			cnt++;
		}
	}
	/*
	for (int i = 0; i < sum; i++){
		cout << s[i];
	}cout << endl;*/
	cout << cnt;
	return 0;
}
