#include<bits/stdc++.h>
using namespace std;

int b[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s = "";
	int n;
	long long ans = 0;
	cin >> n;
	for(int i = 0; i < n; i ++) {
		int t;
		char a;
		cin >> t >> a;
		b[i] = t;
		s += a;
	}
	int s2 = 0;
	for(int i = 1; i < s.size(); i ++) {
		if(s[i] == s[i - 1]) {
			s2 ++;
		}else {
			break;
		}
	}
	if(s2 + 1 == s.size()) {
		cout << 0;
		return 0;
	}
	int s1 = s.size() - 1,i = 0;
	while(1) {
		if(b[i] > b[s1 - i - 1]) {
			ans += b[s1 - i - 1];
			b[i] -= b[s1 - i - 1];
			s1 --;
		}else if(b[i] < b[s1 - i - 1]){
			ans += b[i];
			i ++;
			b[s1 - i - 1] -= b[i];
		}else {
			ans += b[i];
			s1 --;
			i ++;
		}
		if(s1 == 1 || s1 == i) {
			break;
		}
	}
	
	cout << ans;
	
	return 0;
}
