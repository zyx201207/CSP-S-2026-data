#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	char c1[5];
	char s1[5];
	char c2[5];
	char s2[5];
	cin >> c1[0] >> c1[1] >> s1[0] >> s1[1]>>s1[2]>> c2[0] >> c2[1] >> s2[0] >> s2[1]>>s2[2];
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout <<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout << "1";
			if(s1[2]-'A'>=3&&(s1[2]-'A')+(s2[2]-'A')==8){
				cout << "1";
				if(s1[2]-'A'+1==s2[2]-'A'||s1[2]-'A'-1==s2[2]-'A') cout << "1";
				else cout << "0";
			} 
			
			else if(s1[2]-'A'<3&&(s1[2]-'A')+(s2[2]-'A')<=3){
				cout << "1";
				if(s1[2]-'A'+1==s2[2]-'A'||s1[2]-'A'-1==s2[2]-'A') cout << "1";
				else cout <<"0";
			}
			else cout << "00";
		}
		else cout << "000"	;	
	}
	else cout << "0000";
	return 0;
} 
