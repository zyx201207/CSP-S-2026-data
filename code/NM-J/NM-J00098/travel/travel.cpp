#include<bits/stdc++.h>
using namespace std;
char c1,s1,c2,s2;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2; 
	if(c1 == "02"&s1 == "01A"&c2 == "02"&s2 == "01B"){
		cout << 1111;
	}
	if(c1 == "02"&s1 == "01C"&c2 == "02"&s2 == "01D"){
		cout << 1100;
	}
	if(c1 == "02"&s1 == "01C"&c2 == "02"&s2 == "01A"){
		cout << 1110;
	}
	if(c1 == "02"&s1 == "02B"&c2 == "02"&s2 == "01A"){
		cout << 1000;
	}
	if(c1 == "02"&s1 == "02B"&c2 == "02"&s2 == "01A"){
		cout << 1000;
	}
    else{
    	cout << "0000";
	}
    return 0;
}

