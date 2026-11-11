#include <bits/stdc++.h>
using namespace std;;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2, a[10] = {};
	int i = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) {
		i += 1000;
	for(int j = 0 ; j < 3 ; j++){
		a.append(s1[j]);
	} 	
	for(j = 0 ; j < 3 ; j++){
		a.append(s2[j]);
	}
	if(a[1] == a[3] && a[0] = a[2]){
		i += 100;
	}
	if(a[5]+a[6] == "AB"||a[5]+a[6] == "AC"||a[5]+a[6] == "BC"||a[5]+a[6] == "DF"||a[5]+a[6] == "BA"||a[5]+a[6] == "CA"||a[5]+a[6] == "CB"||a[5]+a[6] == "FD"){
		i += 10;
	}
	if(a[5]+a[6] == "AB"||a[5]+a[6] == "DF"||a[5]+a[6] == "BA"||a[5]+a[6] == "BC"||a[5]+a[6] == "CB"||a[5]+a[6] == "FD"){
		i += 1;
	}
	cout << i;
	return 0;}
