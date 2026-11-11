//马辰宇，西安市远东第一中学，SN-J00633; 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	char c1,c2;
	cin >> c1 >> s1;
	cin >> c2 >> s2;
	if(c1 == c2){
		cout << true;
		if((s1[0] == s2[0]) && (s1[1] == s2[1])){
			cout << true;
			if(s1[2] == 'A' || 'B' || 'C' && s2[2] == 'A' || 'B' || 'C'){
				cout << true;
				if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B')){
					cout << true;
				}
				else{
					cout << false;
				}
			}
			else if(s1[3] == 'E' || 'F' && s2[3] == 'E' || 'F'){
				cout << true;
				if((s1[2] == 'F' && s2[2] == 'E') || (s1[2] == 'E' && s2[2] == 'F')){
					cout << true;
				}
				else{
					cout << false;
				}
			}
			else{
				cout << false << false;
			}
		}
		else{
			cout << false << false << false;
		}
	}
	else{
		cout << false << false << false << false;
	}
	return 0;
}
