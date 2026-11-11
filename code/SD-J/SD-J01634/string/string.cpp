#include<bits/stdc++.h>
using namespace std;

int n;
string s;
long long a;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	
	cin >> n;
	while (n--) {
		
		string b;
		cin >> a;
		cin >> b;
		
		for (int i = 1; i <= a; i++) {
			s += b;
		}
		
		
	}
	
	long long sz = s.size();
	
	long long le = 0, ri = sz;
	long long ans = 0;

	bool d = false;
	for(int i = 0; i < sz; i++) {
		if(s[i] != s[0]) {
			d = true;
		}
	}
	if(!d) {
		cout << 0;
		return 0;
	}
	
	while (!(le > ri)) {
		if(s[le] != s[ri]) {
			ans++;
		}
		le++;
		ri--;
	}
	
	cout << ans;
	
	return 0;
} 

