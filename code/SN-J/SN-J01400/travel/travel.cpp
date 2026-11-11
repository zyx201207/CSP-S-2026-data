#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
	string c1, s1, c2, s2, s;
	int n, m, x, y;
	n = 0;
	m = 0;
	s = "0000";
	cin >> c1 >> s1 >> c2 >> s2;
	string ss = "ABCDF";
	if (c1 != c2){
		cout << "0000";
	}else if(s1[0]+s1[1] == s2[0] + s2[1]){
		s[0] = '1';
		s[1] = '1';				 
	}else{
		s[0] = '1';
		cout << s;
	}
	for (int i = 0; i <= 4; i++){
		if (s1[2] == ss[i]){
			x = i;
		}
		if (s2[2] == ss[i]){
			y = i;
		}
		if (s1[2] == ss[i] && i <= 2){
			n += 1;
		}else{
			m += 1;
		}
		if (s2[2] == ss[i] && i <= 2){
			n += 1;
		}else{
			m += 1;
		}
	}
	if (n == 2 || m == 2){
		s[2] = '1';
	}else if(ss[x] == 'A' && ss[y] == 'A'){
		cout << s;
	}else if(ss[x] == 'C' && ss[y] == 'A'){
		cout << s;
	}else {
		s[3] = '1';
		cout << s;
	}
	return 0;
	}
