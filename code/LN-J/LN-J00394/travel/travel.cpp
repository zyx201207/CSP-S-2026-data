#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string f1, f2;
	f1=s1[0]+s1[1];
	f2=s2[0]+s2[1];
	bool ok1, ok2, ok3, ok4;
	if(c1==c2){ok1=true;}
		
	if(f1==f2){ok2=true;}
	
	if(s1[2]=='A'&&(s2[2]=='B' || s2[2]=='C')) ok3=true;
	if(s1[2]=='B'&&(s2[2]=='A' || s2[2]=='C')) ok3=true;
	if(s1[2]=='C'&&(s2[2]=='A' || s2[2]=='B')) ok3=true;
	if((s1[2]=='D'&&s2[2]=='F') || (s1[2]=='F'&&s2[2]=='D')){
		ok3=true;
		ok4=true;
	}
	
	if(s1[2]=='B' || s2[2]=='B') ok4=true;
	
	if(ok1){
		cout << '1';
		if(ok2){
			cout << '1';
			if(ok3){
				cout << '1';
				if(ok4){
					cout << '1';
				}
				else{
					cout << '0';
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
}
