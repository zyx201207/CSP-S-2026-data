#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	char e,f;
	scanf("0%d 0%d%c 0%d 0%d%c",&a,&c,&e,&b,&d,&f);
	if(a==b){
		cout<<'1';
		if(c==d){
			cout<<'1';
			if((e=='D'&&f=='E')||(e=='E'&&f=='D')||(e=='A'&&f=='B')||(e=='A'&&f=='C')||(e=='B'&&f=='A')||(e=='B'&&f=='C')||(e=='C'&&f=='A')||(e=='C'&&f=='B')){
				cout<<'1';
				if((e=='A'&&f=='B')||(e=='B'&&f=='A')||(e=='B'&&f=='C')||(e=='C'&&f=='B')||(e=='D'&&f=='E')||(e=='E'&&f=='D'))cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
