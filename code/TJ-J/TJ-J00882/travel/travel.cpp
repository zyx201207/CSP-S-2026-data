#include <bits/stdc++.h>
using namespace std;
struct cs{
	int c;
	string s;
	bool m=0;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cs a,b;
	bool n=0;
	cin >> a.c >> a.s >> b.c >>b.s;
	
	if(a.c==b.c){
		cout << "1";
	}else{
		cout <<"0";
	}
	if(a.c==b.c && a.s[0]==b.s[0] && a.s[1]==b.s[1]){
		cout << "1";
	}else{
		cout << "0";
	}
	if(a.s[2]=='A' ||a.s[2]=='B' || a.s[2]=='C'){
		a.m=1;
	}if(b.s[2]=='A' ||b.s[2]=='B' || b.s[2]=='C'){
		b.m=1;
	}
	if(a.c==b.c && a.s[0]==b.s[0] && a.s[1]==b.s[1] && a.m==b.m){
		cout << "1";
	}else{
		cout << "0";
	}
	if((b.s[2]=='A' && a.s[2]=='C') || (a.s[2]=='A' && b.s[2]=='C')){
		n=1;
	}if(a.c==b.c && a.s[0]==b.s[0] && a.s[1]==b.s[1] && a.m==b.m && n==0){
		cout << "1";
	}else{
		cout <<"0";
	}
	return 0; 
}
 
