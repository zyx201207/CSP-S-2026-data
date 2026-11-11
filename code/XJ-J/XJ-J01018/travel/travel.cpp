#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int a[4];
	if(c1==c2) {
		a[0]=1;
	} else {
		a[0]=0;
	}
	char b1=s1[2];
	char b2=s2[2];
	s1[2]=' ';
	s2[2]=' ';
	if(s1==s2) {
		a[1]=1;
	} else {
		a[1]=0;
	}
	if(b1>='A'&&b1<='C'&&b2>='A'&&b2<='C') {
		a[2]=1;
	} else if(b1>='D'&&b1<='F'&&b2>='D'&&b2<='F') {
		a[2]=1;
	} else {
		a[2]=0;
	}
	if(a[2]==1) {


		if(b1+1==b2||b1-1==b2) {
			a[3]=1;
			
		}
		else{
			a[3]=0;
		}
	}
	else{
		a[3]=0;
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	return 0;
}