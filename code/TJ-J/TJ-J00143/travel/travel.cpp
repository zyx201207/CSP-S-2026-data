#include <iostream>
using namespace std;
char c1, c2, s1, s2;
char a, b, c, d;
int main{
	cin>>c1, s1, c2, s2;
	if(c1 == c2){
		a = "1";		
	}
	if(c1 != c2){
		a = "0";
	}
	if(s1 - s2 <= 4 || s2 - s1 <= 4){
		b = "1";
		if(s1 - s2 == 1 || s2 - s1 == 1 ){
			c = "1";
			if(s1[2] == C && s2[2] == D){
				c = "0";
			}
		}
	}
	if(s1 - s2 > 4 || s2 - s1 > 4){
		b = "0";
		c = "0";
	}
	if(s1[2] == "A" && s2[2] == "C"){
		c = "1";
		d = "0";
	}
	if(s1[2] == "C" && s2[2] == "A"){
		c = "1";
		d = "0";
	}
	if(s1[2] != "A" && s2[2] == "C" && c == "1"){
		d = "1";
	}
	if(s1[2] != "C" && s2[2] == "A" && c == "1"){
		d = "1";
	}
	cout<<a<<b<<c<<d;
} 
