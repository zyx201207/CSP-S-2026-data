#include<bits/stdc++.h>
using namespace std;
string a;
string b;
string c;
string d;
int number;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a == c){
		number += 1000;
	}
	
	if(b == "01A" && d == "01B"){
			number += 111;
		}else if(b == "01A" && d == "01C"){
			number += 110;
		}else if(b == "01A" && d == "01D"){
			number += 100;
		}else if(b == "01A" && d == "01F"){
			number += 100;
		}else if(b == "01D" && d == "01F"){
			number += 111;
		}else if(b == "01B" && d == "01A"){
			number += 111;
		}else if(b == "01B" && d == "01C"){
			number += 111;
		}else if(b == "01C" && d == "01B"){
			number += 111;
		}else if(b == "01B" && d == "01F"){
			number += 100;
		}else if(b == "01F" && d == "01B"){
			number += 100;
		}else if(b == "01C" && d == "01A"){
			number += 110;
		}else if(b == "01D" && d == "01A"){
			number += 100;
		}else if(b == "01F" && d == "01A"){
			number += 100;
		}else if(b == "01F" && d == "01D"){
			number += 111;
		}else if(b == "01C" && d == "01F"){
			number += 100;
		}else if(b == "01F" && d == "01C"){
			number += 100;
		}else if(b == "01D" && d == "01F"){
			number += 111;
		}else if(b == "01F" && d == "01D"){
			number += 111;
		}else if(b == "01B" && d == "01D"){
			number += 100;
		}else if(b == "01D" && d == "01B"){
			number += 100;
		}else if(b == "01C" && d == "01D"){
			number += 100;
		}else if(b == "01D" && d == "01C"){
			number += 100;
		}else if(b == "01F" && d == "01C"){
			number += 100;
		}else{
			number += 000;
		}
	
	cout << number;
	return 0;
}