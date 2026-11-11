#include<bits/stdc++.h>
#define int long long
#define QwQ 0
#define debug cout << "!!!" << "\n";
using namespace std;
string c1, s1, c2, s2;
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			int num1 = s1[2] - 'A' + 1;
			int num2 = s2[2] - 'A' + 1;
			if(num1 <= 3 && num2 <= 3){
				cout << "1";
				if(abs(num1 - num2) == 1)	cout << "1" << '\n';
				else	cout << "0" << '\n';
			}else if(num1 > 3 && num2 > 3){
				cout << "11" << '\n';
			}else{
				cout << "00" << '\n';
			}
		}else{
			cout << "000" << '\n';
			return QwQ;
		}
	}else{
		cout << "0000" << '\n';
		return QwQ;
	}
	return QwQ;
}