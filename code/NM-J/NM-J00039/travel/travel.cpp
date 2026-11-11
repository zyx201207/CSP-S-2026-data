#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char B = s1[s1.size()-1];
	char C = s2[s2.size()-1];
	if (c1 == c2){
		cout << 1;
		if (s1.substr(0,2) == s2.substr(0,2)){
			cout << 1;
			if (B % 65 <= 2 && C % 65 <= 2 || B % 65 >= 3 && C % 65 >= 3){
				cout << 1;

				if (abs(B % 65 - C % 65) == 1){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}




	return 0;
}
