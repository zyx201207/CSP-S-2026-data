#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	getline(cin,s);
	if(s[0]+s[1]==s[7]+s[8]) cout << 1;
	else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if(s[3]+s[4]==s[10]+s[11]){
		cout << 1;
		if(s[5]<='C' && s[12]<='C'){
			cout << 1;
			if(s[5]+1==s[12] || s[12]+1==s[5]){
				cout << 1;
			}else cout << 0;
		}
		else if(s[5]>='D' && s[12]<='D'){
			cout << 1;
			if(s[5]+1==s[12] || s[12]+1==s[5]){
				cout << 1;
			}else cout << 0;
		}
		else{
			cout << 0;
			if(s[5]+1==s[12] || s[12]+1==s[5]){
				cout << 0;
			}else cout << 0;
		}
	}else{
		cout << 0;
		if(s[5]<='C' && s[12]<='C'){
			cout << 0;
			if(s[5]+1==s[12] || s[12]+1==s[5]){
				cout << 0;
			}else cout << 0;
		}
		else if(s[5]>='D' && s[12]<='D'){
			cout << 0;
			if(s[5]+1==s[12] || s[12]+1==s[5]){
				cout << 0;
			}else cout << 0;
		}
		else{
			cout << 0;
			if(s[5]+1==s[12] || s[12]+1==s[5]){
				cout << 0;
			}else cout << 0;
		}
	}
	
	return 0;
}
