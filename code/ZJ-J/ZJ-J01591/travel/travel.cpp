#include<bits/stdc++.h>
using namespace std;

int csToNum(string s){
//	if(s[0] == '0') return s[1] - '0';
	return (s[0] - '0') * 10 + s[1] - '0';
}
int where(string s){
	int letter = s[2];
	if(letter == 'F'){
		return 5;
	}
	if(letter == 'D'){
		return 4;
	}
	return letter - 'A';
}
bool whe(string s){
	int letter = s[2];
	if(letter == 'A' || letter == 'B' || letter == 'C')
		return 1;
	return 0;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(csToNum(c1) == csToNum(c2))
		cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	if(csToNum(s1) == csToNum(s2)){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	if(whe(s1) == whe(s2)){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}
	if(where(s1) - where(s2) == 1 || where(s1) - where(s2) == -1) {
		cout << 1;
	}
	else{
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
