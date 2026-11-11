#include<bits/stdc++.h> 
using namespace std;
bool asd (char a,char s){
	if (a == 'A' and (s == 'B' or s == 'C')){
		return true;
	}
	if (a == 'B' and (s == 'A' or s == 'C')){
		return true;
	}
	if (a == 'C' and (s == 'A' or s == 'B')){
		return true;
	}
	if (a == 'D' and s == 'F'){
		return true;
	}
	if (a == 'F' and s == 'D'){
		return true;
	}
	return false;
}
bool dsa(char a,char s){
	if (a == 'A' and s == 'B')
		return true;
	if (a == 'B' and s == 'A')
		return true;
	if (a == 'B' and s == 'C')
		return true;
	if (a == 'C' and s == 'B')
		return true;
	if (a == 'D' and s == 'F')
		return true;
	if (a == 'F' and s == 'D')
		return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << 1;
	}
	else cout << 0;
	if (c1 == c2 and s1[0] == s2[0] and s1[1] == s2[1]){
		cout << 1;
	}
	else cout << 0;
	if (c1 == c2 and s1[0] == s2[0] and s1[1] == s2[1] and asd(s1[2],s2[2])){
		cout << 1;
	}
	else cout << 0;
	if (c1 == c2 and s1[0] == s2[0] and s1[1] == s2[1] and dsa(s1[2],s2[2])){
		cout << 1;
	}
	else cout << 0;
	return 0;
}
