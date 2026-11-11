#include <bits/stdc++.h>
using namespace std;
int a[200005];
string s, s1, s2;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	unsigned long long n, ans = 1, cnt = 0, now = 0, pos = 1, i;
	cin >> n;
	for(i = 1; i <= n; i++){
		cin >> a[i] >> s[i];
		now += a[i];
	}
	for(i = 1; i <= n; i++){
		for(int j = 1; j <= a[i]; j++){
			s2[pos] = s[i];
			pos++;
		}
	}
	int flag = 0;
	for(i = 1; i <= now; i++){
		
		if(s2[i] != s2[i-1]){
			flag = 1;
		}
	}
	if(flag == 0){
		cout << 0;
		return 0;
	}
	for(i = now; i >= 1; i--){
		s1[ans] = s2[i];
		ans++;
	}
	ans = 1;
	for(i = now; i >= 1; i--){
		if(s1[i] != s2[i]){
			s2[i] = s1[i];
			s1[ans] = s1[i];
			cnt++;
		}
		ans++;
	}
	cout << cnt;
	return 0;
}
