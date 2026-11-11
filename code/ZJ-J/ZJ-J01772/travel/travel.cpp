#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool f1, f2;
int main(){
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >>c1>>s1>>c2>>s2;
	if (c1 == c2){
		printf ("1");
	} else {
		printf ("0000");
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]){
		printf ("1");
	} else {
		printf ("000");
		return 0;
	}
	if (s1[2] <= 'C'){
		f1 = true;
	} else {
		f1 = false;
	}
	if (s2[2] <= 'C'){
		f2 = true;
	} else {
		f2 = false;
	}
	if (f1 == f2){
		printf ("1");
	} else {
		printf ("00");
		return 0;
	}
	if (abs(s1[2] - s2[2]) == 1){
		printf ("1");
	} else {
		printf ("0");
		return 0;
	}
	return 0;
}

