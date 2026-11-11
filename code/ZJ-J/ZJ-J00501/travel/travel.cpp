#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	if(s[0]==s[7]&&s[1]==s[8]){
		cout<<"1";
		if(s[3]==s[10]&&s[4]==s[11]){
			cout<<"1";
			if(s[5]=='A'||s[5]=='B'||s[5]=='C'){
				if(s[12]=='A'||s[12]=='B'||s[12]=='C'){
					cout<<"1";
					if(abs(s[5]-s[12])==1){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"00";
				}
			}else{
				if(s[12]=='D'||s[12]=='F'){
					cout<<"1";
					if(abs(s[5]-s[12])==1){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
