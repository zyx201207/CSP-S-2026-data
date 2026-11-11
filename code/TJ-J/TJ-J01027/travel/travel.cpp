#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen( "travel.in" , "r" , std );
	freopen( "travel.out" , "w" , std );
	int c1, c3;
	char s1[10], s2[10];
	cin >> c1 >> s1 >> c3 >> s2;
	if( c1 == c3 ){
		cout << "1";
		if( s1[1] == s2[1] ){
			cout << "1";
			if( ( (s1[2] =='A' || s1[2] =='B' || s1[2] == 'C' ) && ( s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C' ) ) || ( ( s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))){
				cout << "1";
				if( abs(s1[2] - s2[2]) <= 1 || ( ( s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F') ) ){
					cout << "1";
				}else{
					cout << "0";
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
