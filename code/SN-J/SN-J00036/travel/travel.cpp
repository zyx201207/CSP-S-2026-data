#include<bits/stdc++.h>
using namespace std;
int main(){
	char c1,s1;
	char c2,s2;
	int cs2,ss2;
	int tiaojian1 = 0,tiaojian2 = 0,tiaojian3 = 0,tiaojian4 = 0;
	cin >> c1 >> c2 >> s1 >> s2;
	//cout << s1;
	//cout << c2 << s2;
	if(c1 == s1){
		tiaojian1 = 1;
	} else {
		tiaojian1 = 0;
	}
	//cout << c1 << " "<<s1 <<" "<<c2 <<" "<<s2;
	if(cs2 == ss2){
		tiaojian2 = 1;
	} else {
		tiaojian2 = 0;
	}
	
	if(c2 == s2){
		tiaojian3 = 1;
	} else {
		tiaojian3 = 0;
	}
	
	if(c1 == s1){
		tiaojian4 = 1;
	} else {
		tiaojian4 = 0;
	}
	
	cout << tiaojian1 << tiaojian2 << tiaojian3 << tiaojian4;
	return 0;
}
