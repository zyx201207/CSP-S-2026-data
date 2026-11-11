#include <bits/stdc++.h>
using namespace std;
int main(){                              
	freopen("treval.in","r",stdin);
	freopen("treval.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2){
		cout << "0000";
	}
	else{
		if (s1[0] == s2[0] && s1[1] == s2[1]){
			if(s1[2] == 'A'){
				if (s2[2] == 'B'){
					cout << "1111";
				}
				else if(s2[2] == 'C'){
					cout << "1110";
				}
				else{
					cout << "1100";
				}
			} 
			else if(s1[2] == 'B'){
				if (s2[2] == 'A' || s2[2] == 'C'){
					cout << "1111";
				}
				else{
					cout << "1100";
				}
			}
			else if(s1[2] == 'C'){
				if (s2[2] == 'A'){
					cout << "1110";
				}
				else if(s2[2] == 'B'){
					cout << "1111";
				}
				else{
					cout << "1100";
				}
			}
			else if(s1[2] == 'D'){
				if(s2[2] == 'E'){
					cout << "1111";
				}
				else{
					cout << "1100";
				}
			}
			else{
				if (s2[2] == 'D'){
					cout << "1111";
				}
				else{
					cout << "1100";
				}
			}
		}
		else{
			cout << "1000";
		}
	}
	return 0;
}
