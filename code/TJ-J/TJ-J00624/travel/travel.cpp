#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2) cout << 1;
	else{
		cout << 0 << 0 << 0 << 0 << endl; 
		return 0;
 
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0]) {
		cout << 1;
	}
	else{
		cout << 0 << 0 << 0 << endl;
		return 0;
	}
	
	if(s1[2]=='A'||s1[2]=='C'||s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C'||s2[2]=='B'){
			cout << 1;
			if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s1[2]=='A') {
				cout << 1;
			}
			else if(s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s1[2]=='B') {
				cout << 1;
			}
			else {
				cout<<0;
			}
		}
	}
	else if(s2[2]=='D'||s2[2]=='E'){
		cout << 1;
		if(s1[2]=='D'&&s2[2]=='E'||s1[2]=='E'&&s1[2]=='D') {
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]=='D'||s2[2]=='E'){
			cout << 0 << 0 <<endl;
		}
	}
	if(s1[1]=='D'||s1[2]=='E'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			cout << 0 << 0 <<endl;
		}
	}
	return 0;
}
