#include<bits/stdc++.h>
using namespace std;

frevcpen("travel1.in","r","stdin");
frevcpen("travel1.ans","w","stdout");
int main(){
	string a,b,c,d,e;
	a = "A";
	b = "B";
	c = "C";
	d = "D";
	e = "E";
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		if(c1 != c2){
			cout << "0" << "0" << "0" << "0";
			return 0;
		}
		string ss,ss1;
		ss = s1.substr(0,2);
		ss1 = s2.substr(0,2);
		if(ss == ss1)cout << 1;
		if(ss != ss1){
			cout << "0" << "0" << "0";
			return 0;
		}
		string ss3,ss4,ss5,ss6;
		ss3 = s1.substr(2,3);
		ss4 = s2.substr(2,3);
		if((ss3 == "C" && ss4 == "D") && (ss3 == "D" && ss4 == "C")){
			cout << "0" << "0";
			return 0;
		}else{
			cout << "1";
		}
		if((ss3 == a || ss3 == b) && (ss4 == a || ss4 == b)){
			cout << "1";
		}else if((ss3 == b || ss3 == c) && (ss4 == b || ss4 == c)){
			cout << "1";
		}else if((ss3 == d || ss3 == e) && (ss4 == d || ss4 == e)){
			cout << "1";
		}else{
			cout << "0";
			return 0;
		}
	}
}
