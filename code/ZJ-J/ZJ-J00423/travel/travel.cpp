#include <bits/stdc++.h>
using namespace std;

void fn(char a,char b){
	if (a=='A'||a=='B'||a=='C'){
		if (b=='A'||b=='B'||b=='C'){
			cout << '1';
			if (b-a==1){
				cout << '1';
				return;
			}
			else{
				cout << '0';
				return;
			}
		}
		else{
			cout << "00";
			return;
		}
	}
	else{
		if (a=='F'){
			cout << "00";
			return;
		}
		else cout << "11";
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if (c1==c2){
		cout << '1';
		int a=(s1[0]-'0')*10+(s1[1]-'0'),
			b=(s2[0]-'0')*10+(s2[1]-'0');
		if (a==b){
			cout << '1';
			if (s1[2]<s2[2]) fn(s1[2],s2[2]);
			else fn(s2[2],s1[2]);
		}
		else cout << "000";
	}
	else cout << "0000";
	
	return 0;
}