#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,l = 0,cnt = 0;
	char c;
	string s;
	cin >> n;
	for (int i = 0;i < n;i++){
		cin >> a >> c;
		l += a;
		for (int j = 0;j < a;j++){
			s += c;
		} 
	} 
	int q = 0,p = l - 1;
	while (q <= p){
		if (s[q] != s[p]){
			cnt++;
		} 
		q++;
		p--;
	} 
	cout << cnt;
	return 0;
} 
