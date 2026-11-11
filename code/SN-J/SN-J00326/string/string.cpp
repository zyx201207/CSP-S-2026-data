#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s, s1;
int k, q;
long long l;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		int a;
		char b;
		string si;
		cin >> a >> b;
		l += a;
		for(int i = 0;i < a;i ++){
			s[k] = b;
			k ++;
		}
	}
	for(int i = k - 1;i >= 0;i --){
		s1[q] = s[i];
		q ++;
	}
	for(int i = 0;i < k;i ++){
		if(s[i] != s1[i]){
			ans ++;
		}
	}
	cout << ans / 2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
