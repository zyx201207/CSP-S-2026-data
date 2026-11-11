#include <bits/stdc++.h>
using namespace std;
map <string, int> mp;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	mp["A"] = 1;
	mp["B"] = 2;
	mp["C"] = 3;
	mp["D"] = 5;
	mp["F"] = 6;
	int n, m;
	string s1, s2;
	cin >> n >> s1 >> m >> s2;
	if(n == m){
		cout << 1;
		string s3 = "";
		s3.push_back(s1[0]);
		s3.push_back(s1[1]);
		string s4 = "";
		s4.push_back(s2[0]);
		s4.push_back(s2[1]);
		if(s3 == s4){
			cout << 1;
			s3 = "";
			s3.push_back(s1[2]);
			s4 = "";
			s4.push_back(s2[2]);
			if(abs(mp[s3] - mp[s4]) == 1 || (max(mp[s3], mp[s4]) == 3 && min(mp[s3], mp[s4]) == 1)){
				cout << 1;
				if(abs(mp[s3] - mp[s4]) == 1) cout << 1;
				else cout << 0;
			}else cout << 0 << 0;
		}else cout << 0 << 0 << 0;
	}else cout << 0 << 0 << 0 << 0;
	return 0;
}
