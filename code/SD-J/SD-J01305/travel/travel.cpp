#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a1, a2;
	string b1, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	int s1, s2;
	s1=(b1[0]-'0')*10+(b1[1]-'0');
	s2=(b2[0]-'0')*10+(b2[1]-'0');
	char d1, d2;
	d1=b1[2];
	d2=b2[2];
	if(a1==a2){
		cout << "1";
		if(s1==s2){
			cout << "1";
			if(d2<='C'&&d1<='C'){
				cout << "1";
			}
			else if(d1>='D'&&d2>='D'){
				cout << "1";
			}
			else{
				cout << "0";
			}
		}
		else{
			cout << "00";
		}
	}
	else{
		cout << "000";
	}
	if(s1==s2){
		if(abs(d1-d2)==1&&(d1!='C'&&d2!='D')&&(d1!='D'&&d2!='C')){
			cout << "1";
		}
		else if((d1=='D'&&d2=='F')||(d1=='F'&&d2=='D')){
			cout << "1";
		}
		else{
			cout << "0";
		}
	}
	else{
		cout << "0";
	}
	return 0;
} 
