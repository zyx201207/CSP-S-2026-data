#include<bits/stdc++.h>
using namespace std;
string c1, c2, s1, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	} cout << "1";
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		cout << "1";
	}else{
		cout << "000"; return 0;
	}
	if(s1[2] >= 'D' && s2[2] >= 'D'){
		cout << "11";
	}else if(s1[2] <= 'C' && s2[2] <= 'C'){
		cout << "1";
		if((s1[2] == 'A' && s2[2] == 'B') || (s2[2] == 'A' && s1[2] == 'B')){
			cout << "1";
		}else if((s1[2] == 'B' && s2[2] == 'C') || (s2[2] == 'B' && s1[2] == 'C')){
			cout << "1";
		}else cout << "0";
	}else cout << "00";
	return 0;
}