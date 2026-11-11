#include<bits/stdc++.h>
using namespace std;
long long n, l, cnt, m;
string s, a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> m >> a;
		while (m --){
			s += a;
		}
	}
	l = s.size();
	for (int i = 0; i < l; i ++) cout << s[i]; 
	for (int i = 0; i <= l / 2; i ++){
		if (s[i] != s[l - i - 1]) cnt ++;
	}
	cout << cnt;
	return 0;
}
