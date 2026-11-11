#include <bits/stdc++.h>
using namespace std ;
int main () {
	freopen("travel.in", "r",stdin) ;
	freopen("travel.out", "w",stdout) ;
	int S, C ;
	string c[5] ;
	string s[5] ;
	cin >> C ;
	cin >> c ;
	cin >> S ;
	cin >> s ;
	if(S == C){
		cout << "1" ;
		if(c[1] == s[1]){
			if(c[2] == s[2]){
				cout << "1" ;
				if(c[3] == 'A'||c[3] == 'B'||c[3] == 'C'){
					if(s[3] == 'A'||s[3] == 'B'||s[3] == 'C'){
						cout << "1" ;
						if(c[3] == "A" && s[3] == "B"){
							cout << "1" ;
						}
						else if (c[3] == "B" && s[3] == "A"){
							cout << "1" ;
						}
						else if (c[3] == "C" && s[3] == "B"){
							cout << "1" ;
						}
						else if (c[3] == "B" && s[3] == "C"){
							cout << "1" ;
						}
						else {
							cout << "0" ;
						}
					}
					else{
						cout << "00" ;
					}
				}
				else if (c[3] == 'D'||c[3] == 'F'){
					if(s[3] == 'D'||s[3] == 'F'){
						cout << "1" ;
						if(c[3] == "D" && s[3] == "F"){
							cout << "1" ;
						}
						else if (c[3] == "F" && s[3] == "D"){
							cout << "1" ;
						}
						else {
							cout << "0" ;
						}
					}
					else{
						cout << "00" ;
					}
				}
			}
			else {
				cout << "000" ;
			}
		}
	}
	else {
		cout << "0000" ;
	}
	return 0 ;
}