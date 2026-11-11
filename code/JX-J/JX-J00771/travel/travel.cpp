#include<bits/stdc++.h>
using namespace std;

int x1,x2,l1=0,l2=0;
char a1,a2;
string s2,s4;

bool check1(char c){
	return c == 'A' || c == 'B' || c == 'C';
}

bool check2(char c){
	return c == 'D' || c == 'F';
}

bool check3(char c,char v){
	if(check1(c)&&check1(v)){
		if(c=='A'){
			return v == 'B';
		}else if(c == 'B'){
			return true;
		}else{
			return v == 'B';
		}
	}else{
		return true;
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> x1 >> s2 >> x2 >> s4;

	// cout << a1 << ' ' << x2 << '\n';

	a1 = s2[2],a2 = s4[2];

	l1 = (s2[0]-'0')*10 + (s2[1]-'0');
	l2 = (s4[0]-'0')*10 + (s4[1]-'0');

	if(x1 == x2){
		cout << 1;
		if(l1==l2){
			cout << 1;
			if((check1(a1)&&check1(a2))||(check2(a1)&&check2(a2))){
				cout << 1;
				if(check3(a1,a2)){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}

	return 0;
}