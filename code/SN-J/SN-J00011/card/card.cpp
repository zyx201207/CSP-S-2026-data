#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	string s = "";
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++) {
		int a;
		cin >> a;
		s += char(a + 48);
	}
	string s1 = s;
	for(int i = 0; i < m; i ++) {
		int ans = 0;
		for(int j = 0; j < n; j ++) {
			for(int k = j; k < n; k ++) {
				string a;
				a = s1[k];
				if(s.find(a) != string::npos) {
					s.erase(s.find(a) + 1,s.size());
				}else {
					s += a;
				}
			} 
			string c;
			c = char(i + 49);
			if(s.find(c) != string::npos) {
				ans ++;
			}
			s = s1;
		}
		if(i == 0) {
			ans --;
		}
		cout << ans << " ";
	}
	
	return 0;
}
