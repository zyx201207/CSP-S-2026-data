#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
	}
	else{
		cout << "0000";
		return 0;
	}
	
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		cout << "1";
	}
	else{
		cout << "000";
		return 0;
	}
	
	char st1 = s1[2], st2 = s2[2];
	if(abs(st1 - st2) > 2){
		cout << "00";
		return 0;
	}
	else if((st1 == 'B' || st1 == 'C') && st2 == 'D'){
		cout << "00";
		return 0;
	}
	else if((st2 == 'B' || st2 == 'C') && st1 == 'D'){
		cout << "00";
		return 0;
	}
	else cout << "1";
	
	if(abs(st1 - st2) == 1 || (st1 == 'D' || st2 == 'D')){
		cout << "1";
	}
	else cout << "0";
	return 0;
}