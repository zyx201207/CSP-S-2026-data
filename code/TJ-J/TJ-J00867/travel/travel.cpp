#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << "1";
	}
	else {
		cout << "0";
	}
	string d1,d2;
	d1 += s1[0];
	d1 += s1[1];
	d2 += s2[0];
	d2 += s2[1];
	if (c1 == c2 && d1 == d2){
		cout << "1";
	}
	else {
		cout << "0";
	}
    string c3,c4;
	c3 += s1[2];
	c4 += s2[2];
	int d3,d4;
	if (c3 == "A"){
		d3 = 1;
	}
	else if (c3 == "B"){
		d3 = 2;
	}
	else if (c3 == "C"){
		d3 = 3;
	}
	else if (c3 == "D"){
		d3 = 4;
	}
	else if (c3 == "F"){
		d3 = 5;
	}
	if (c4 == "A"){
		d4 = 1;
	}
	else if (c4 == "B"){
		d4 = 2;
	}
	else if (c4 == "C"){
		d4 = 3;
	}
	else if (c4 == "D"){
		d4 = 4;
	}
	else if (c4 == "F"){
		d4 = 5;
	}	
	if (c1 == c2 && d1 == d2 && ((d4 <= 3 && d3 <= 3) || (d4 >= 4 && d3 >= 4))){
		cout << "1";
	}
	else {
		cout << "0"; 
	} 
	int ans = max(d3,d4) - min(d3,d4);
	if (c1 == c2 && d1 == d2 && ((d4 <= 3 && d3 <= 3) || (d4>= 4 && d3 >= 4)) && ans == 1){
		if ((d3 == 3 && d4 == 4)||(d3 == 4 && d4 == 3)){
			cout << "0";
		}
		else {
			cout << "1";
		}
	}
	else {
		cout << "0";
	}
	return 0;
}
