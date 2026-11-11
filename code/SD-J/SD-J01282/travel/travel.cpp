#include<bits/stdc++.h>
using namespace std;
string s1, s2, s3, s4;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3){
		cout << 1;
		if(s2[0] == s4[0] && s2[1] == s4[1]){
			cout << 1;
			char a, b;
			if(s2[2] < s4[2]) a = s2[2], b = s4[2];
			else a = s4[2], b = s2[2];
		    if((a =='D' || a == 'F') && (b >='D' || b == 'F'))
				cout << 11;
			else if((a >= 'A' && a <= 'C') && (b >='A' && b <= 'C')){
				cout << 1;
				if((a == 'A' && b == 'B') || (a == 'B' && b == 'C')) cout << 1;
				else cout << 0; 
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";

	return 0;
} 
