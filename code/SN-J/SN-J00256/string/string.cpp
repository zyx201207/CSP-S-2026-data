#include <bits/stdc++.h>
using namespace std;
int n,a,cnt;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a >> c;
		for (int j = 1;j <= a;j++){
			s += c;
		}
	}
	for (int i = 1;i <= a;i++){
		if (s[i] != s[s.size()/2]-i){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
