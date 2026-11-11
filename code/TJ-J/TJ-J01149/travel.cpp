#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	string s="";
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	char a,b;
	if (c1==c2){
		s+='1';
		if (s1[0]==s2[0]&&s1[1]==s2[1]){
			s+='1';
			a=s1[2];
			b=s2[2];
			if (s1[2]>s2[2])swap(a,b);
			if (a=='A'&&(b=='B'||b=='C')||(a=='D'&&a=='F')){
				s+='1';
				if ((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F'))s+='1';
				else s="1110";
			}else {
				s="1100";
			}
		}else {
			s="1000";
		}
	}else {
		s="0000";
	}
	cout << s;
	return 0;
} 

