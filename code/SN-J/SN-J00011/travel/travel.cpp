#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	
	if(s1 == s3) {
		cout << "1";
		char a = s2[s2.size() - 1],b = s4[s4.size() - 1];
		s2.erase(s2.size() - 1,1);
		s4.erase(s4.size() - 1,1);
		if(s2 == s4) {
			cout << "1";
			if(a == 'D' || a == 'F') {
				if(b == 'D' || b == 'F') {
					cout << "11";
				}else {
					cout << "00";
				}
			}else if(a == 'A' || a == 'B' || a == 'C') {
				if(b == 'A' || b == 'B' || b == 'C') {
					cout << "1";
					if(abs(a - b) == 1) {
						cout << "1";
					}else {
						cout << "0";
					}
				}else {
					cout << "00";
				}
			}else {
				cout << "00";
			}
		}else {
			cout << "000";
		}
	}else {
		cout << "0000";
	}
	
	return 0;
} 
