#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char s1_st = s1[2], s2_st = s2[2];
	bool t = false, t2 = false;
	
	if (c1 == c2){
		t2 = true;
		cout << 1;
	}
	else cout << 0;
	
	if (s1[0] == s2[0] && s1[1] == s2[1] && t2) cout << 1;
	else cout << 0;
	
	if (s1[0] == s2[0] && s1[1] == s2[1] && t2){
		if(s1_st <= 67 && s2_st <= 67){
			t = true;
			cout << 1;
		} 
		else if (s1_st >= 68 && s2_st >= 68){
			t = true;
			cout << 1;
		}
		else cout << 0;
	}
	else cout << 0;
	
	if (s1_st - s2_st == 1 && t|| s2_st - s1_st == 1 && t) cout << 1;
	else cout << 0;
	
	return 0;
} 
