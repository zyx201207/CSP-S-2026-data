#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
bool f = 0;
bool check(char x,char y){
	if(x=='A'){
		if(y=='B'||y=='C'){
			return 1;
		}
		return 0;
	}if(x=='B'){
		if(y=='A'||y=='C'){
			return 1;
		}
		return 0;
	}if(x=='C'){
		if(y=='B'||y=='A'){
			return 1;
		}
		return 0;
	}if(x=='D'){
		if(y=='F'){
			return 1;
		}
		return 0;
	}if(x=='F'){
		if(y=='D'){
			return 1;
		}
		return 0;
	}
}
bool check2(char x,char y){
	if(x=='A'){
		if(y=='B'){
			return 1;
		}
		return 0;
	}if(x=='B'){
		if(y=='A'||y=='C'){
			return 1;
		}
		return 0;
	}if(x=='C'){
		if(y=='B'){
			return 1;
		}
		return 0;
	}if(x=='D'){
		if(y=='F'){
			return 1;
		}
		return 0;
	}if(x=='F'){
		if(y=='D'){
			return 1;
		}
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> t1 >> t2;
	if(s1==t1){
		cout << 1;
	}else{
		cout << 0;
		f=1;
	}if(s2[0]==t2[0]&&s2[1]==t2[1]&&f==0){
		cout << 1;
	}else{
		cout << 0;
		f=1;
	}if(check(s2[2],t2[2])&&f==0){
		cout << 1;
	}else{
		cout << 0;
		f=1;
	}if(check2(s2[2],t2[2])&&f==0){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
} 
