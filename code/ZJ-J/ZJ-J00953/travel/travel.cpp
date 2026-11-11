#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool pd(char a,char b){
	if(a>'C') return 1;
	if(a=='A'&&b=='B'||a=='B'&&b=='A'||
	a=='B'&&b=='C'||a=='C'&&b=='B') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<"1";
			if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
				cout<<"1";
				if(pd(s1[2],s2[2])) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
