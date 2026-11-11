#include<bits/stdc++.h>
using namespace std;
int main() {
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin >> c1 >> c2 >> s1 >> s2;
for(int i = 0;i < 2;i++){
	if (i == 0) {
			if (c1[1] == s1[1]){
	cout << "1";
}else {
	cout << "0";
}
	}
if (i==1){
	if (c2[1]== s2[1]){
		cout << "1";
	}else{
		cout << "0";
	}
}
}
if(c1[1]!= s1[1] || c2[1]!=s2[1]) {
	if(c1[1]!= s1[1]){
		cout << "0";
		cout << "0";
		cout << "0";
	}if (s2[2] != s2[1]) {
		cout << "0";
		cout << "0";
	}
}else{
	
for(int i = 0;i < 2;i++){
		if (i == 0){
			if (((c2[2] == 'A' || c2[2] == 'B' || c2[2] == 'C')&&(s2[2]=='A'|| s2[2]=='B'|| s2[2] == 'C'))||((c2[2] == 'D'||c2[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
			cout << "1";
		}else {
			cout << "0";
		}
		}
		if (i==1){
			if(c2[2] +1-'0'== s2[2]-'0'||c2[2]-1-'0'== s2[2] -'0'){
				if (c2[2]== 'C'&& s2[2]== 'D'){
					cout << "0";
				}else{
					cout <<"1";
				}
				
			}else {
			cout << "0";
			}
		}
	}	
}
 return 0;
}
