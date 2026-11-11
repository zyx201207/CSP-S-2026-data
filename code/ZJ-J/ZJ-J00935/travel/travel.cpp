#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	string t1 = s1.substr(0, 2);
	string t2 = s2.substr(0, 2);
	if(t1 != t2){
		cout << "1000";
		return 0;
	}
	t1 = s1.substr(2, 1);
	t2 = s2.substr(2, 1);
	if(t1[0]<='C' && t2[0]>'C' || t1[0]>'C' && t2[0]<='C'){
		cout << "1100";
		return 0;
	}
	
	if(t1[0]=='A' && t2[0]=='B'){
		cout << "1111";
		return 0;
	}
	if(t1[0]=='B' && t2[0]=='A'){
		cout << "1111";
		return 0;
	}
	if(t1[0]=='B' && t2[0]=='C'){
		cout << "1111";
		return 0;
	}
	if(t1[0]=='C' && t2[0]=='B'){
		cout << "1111";
		return 0;
	}
	if(t1[0]=='D' && t2[0]=='F'){
		cout << "1111";
		return 0;
	}
	if(t1[0]=='F' && t2[0]=='D'){
		cout << "1111";
		return 0;
	}
	cout << "1110";
	
	return 0;
}
