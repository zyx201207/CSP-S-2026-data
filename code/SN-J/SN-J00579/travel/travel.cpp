#include <iostream>
using namespace std;
int main() {
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a,b,c,d;
	if(c1 == c2){
		a = 1;
	}
	else{
		a = 0;
	}
	if(s1[0] == s2[0]&&s1[1] == s2[1]){
		b = 1;
	}
	else{
		b = 0;
	}
	if(s1[2] == 'D'||s1[2] == 'F'){
		if(s2[2] == 'D'||s2[2] == 'F'){
			c = 1;
			d = 1;
		}
		else{
			c = 0;
			d = 0;
		}
	}
	else{
		if(s2[2] == 'D'||s2[2] == 'F'){
			c = 0;
			d = 0;
		}
		else{
			c = 1;
			if(s1[2] == 'B'||s2[2] =='B'){
				d = 1;
			}
			else{
				d = 0;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
