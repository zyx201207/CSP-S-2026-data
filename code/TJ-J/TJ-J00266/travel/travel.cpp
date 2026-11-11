#include <bits/stdc++.h> 
using namespace std;
string s1 , s2 , t1 , t2 , SS , TT ;

int flag = 0;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> s1 >> s2 >> t1 >> t2;
	if(s1 == t1){
		//cout << endl << flag << " ";
		cout << "1" ;
	}
	else{
		flag = 1;
		//cout << endl << flag << " " << endl ;
		cout << "0" ;
	}
	string s , t;
	s += s2[0];
	s += s2[1];
	t += t2[0] ;
	t += t2[1];
	//cout << "\n" << s << " " << t << "\n";
	if(s == t && flag == 0) {
		//cout << endl << flag << " ";
		cout << "1" ;
	}
	else {
		cout << "0" ;
		flag = 1;
	}
	string ss , tt ;
	ss = s2[2];
	tt = t2[2];
	SS = s2[2];
	TT = t2[2];
	
	if( (( (ss == "A" || SS == "B" || SS == "C" )&& (TT == "A" || TT == "B" || TT == "C")) || ( (SS == "D" || SS == "F") && ( TT == "D" || TT == "F")) )&& flag == 0 ) {
		cout << "1";
		//cout << endl << flag << " " << endl;
	}
	else {
		flag = 1;
		cout << "0" ;
	}
	

	if(((ss == "A" && tt == "B" )|| (ss == "B" && tt == "C" ) || (ss == "D" && tt == "F") || (tt == "A" && ss == "B" )|| (tt == "B" && ss == "C" ) || (tt == "D" && ss == "F")) && flag == 0) {
		cout << "1"  ;
		//cout << endl << flag << " ";
	}
	else cout << "0";
	return 0;
}
