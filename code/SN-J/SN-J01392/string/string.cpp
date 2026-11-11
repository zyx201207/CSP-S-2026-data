#include<bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long cnt, n, a;
string s, ch;
inline int read(){
	int ans = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans * f;
}
int main(){
	freopen("string.in", "in", stdin);
	freopen("string.out", "out", stdout);
	n = read();
	for (int i = 1; i <= n; i++){
		a = read();
		cin>> ch;
		for (int j = 0; j < a; j++){
			s += ch;
		}
	}
	int ans = s.size() - 1;
	for (int r = 0, l = ans;(l - r) >= 1; r++, l--){
		if (s[r] == s[l]) continue;
		cnt++;
	}
	cout<< cnt;
	return 0;
}
