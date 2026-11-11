#include <bits/stdc++.h>
using namespace std;
void check(char a,char b){
	if(a=='A'&&b=='B'){
		cout << 1111;
	}else if(b=='A'&&a=='B'){
		cout << 1111;
	}else if(a=='B'&&b=='C'){
		cout << 1111;
	}else if(b=='B'&&a=='C'){
		cout << 1111;
	}else if(a=='D'&&b=='E'){
		cout << 1111;
	}else if(b=='D'&&a=='E'){
		cout << 1111;
	}else if(a=='A'&&b=='C'){
		cout << 1110;
	}else if(b=='A'&&a=='C'){
		cout << 1110;
	}else {
		cout << 1100;
	}
}
int main(){
	freopen("treval.in","r",stdin);
	freopen("treval.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		cout << 0000;
	}
	else{
		if((s1[0]-'0')*10+(s1[1]-'0')!=(s2[0]-'0')*10+(s2[1]-'0')){
			cout << 1000;
		}else{
			check(s1[2],s2[2]);
		}
	}
	return 0;
}