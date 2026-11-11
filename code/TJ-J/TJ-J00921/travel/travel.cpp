#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000" << '\n';//che xiang
		return 0;
	}
	string s1d = s1.substr(0, 2);
	string s2d = s2.substr(0, 2);//tong yi pai
	if(s1d != s2d){
		cout << "1000" << '\n';
		return 0;
	}
	char s1b = s1[2];
	char s2b = s2[2];
	if((s1b >= 'A' && s1b <= 'C') && (s2b >= 'A' && s2b <= 'C')){// ABC yi ce
		if(s1b == 'A' && s2b == 'B')cout << "1111" << '\n';
		else if(s1b == 'B' && s2b == 'C')cout << "1111" << '\n';
		else if(s1b == 'B' && s2b == 'A')cout << "1111" << '\n';
		else if(s1b == 'C' && s2b == 'B')cout << "1111" << '\n';
		else cout << "1110" << '\n';
		return 0;
	}else if((s1b >= 'D' && s1b <= 'F') && (s2b >= 'D' && s2b <= 'F')){//DF yi ce
		cout << "1111" << '\n';
		return 0;
	}else {
		cout << "1100" << '\n';
		return 0;
	}
	return 0;
}
