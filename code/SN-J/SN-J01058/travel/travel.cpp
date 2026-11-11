#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1 , c1 ;
	char  s2[4] , c2[4];
	cin >> c1 >>  c2 >> s1 >> s2;
	int count;
	
	if(c1==s1){
		cout << "1";
		if(c2[0]==s2[0] && c2[1]==s2[1]){
			cout << "1";
			if(c2[2]=='A' && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')){
				cout << "1" ;
				count = 100;
			}
			else if(c2[2]=='B' && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')){
				cout << "1" ;
				count = 100;
			}
			else if(c2[2]=='C' && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')){
				cout << "1" ;
				count = 100;
			}
			if(c2[2]=='D' && (s2[2]=='D' || s2[2]=='E')){
				cout << "1";
				count = 100;
			}
			else if(c2[2]=='E' && (s2[2]=='D' || s2[2]=='E')){
				cout << "1";
				count = 100;
			}
			else if(count != 100){
				cout << "00";
			}
			
			if(count == 100){
				if(c2[2]==s2[2]-1  ||  c2[2]==s2[2]+1)
					cout << "1";
				else
					cout << "0";
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
