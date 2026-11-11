#include<bits/stdc++.h>
using namespace std;

string c1,c2;
string s1,s2;

int main(){
	freopen("treval.in","r",stdin);
	freopen("treval.out","w",stdout);
	cin >> c1 >> s1;
	cin >> c2 >> s2;
	int e,f;
	e = 10*(c1[0]-'0')+(c1[1]-'0');
	f = 10*(c2[0]-'0')+(c2[1]-'0');
	if(e == f){
		cout << 1;
	}else{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	int a = 0,b = 0;
	a = 10*(s1[0]-'0')+(s1[1]-'0');
	b = 10*(s2[0]-'0')+(s2[1]-'0');
	if(a == b){
		cout << 1;
	}else{
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	int c,d;
	if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
		c = 0;
	}
	else{
		c = 1;
	}
	if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
		d = 0;
	}
	else{
		d = 1;
	}
	if(c == d){
		cout << 1;
	}else{
		cout << 0;
		cout << 0;
		return 0;
	}
	if(int(s1[2]-s2[2]) == 1 || int(s1[2]-s2[2]) == -1){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
