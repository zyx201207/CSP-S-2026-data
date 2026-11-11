#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	int l=s.size();
	for(int i=0;i<=l-1;i++){
		if(s[0]==s[7]&&s[1]==s[8]){
			cout<<"1";
			break;
		}else{
			cout<<"0";
			break;
		}
	}
	for(int i=0;i<=l-1;i++){
		if(s[0]==s[7]&&s[1]==s[8]&&s[3]==s[10]&&s[4]==s[11]&&s[5]>='A'&&s[5]<='F'&&s[12]>='A'&&s[12]<='F'){
			cout<<"1";
			break;
		}else{
			cout<<"0";
			break;
		}
	}
	for(int i=0;i<=l-1;i++){
		if(s[0]==s[7]&&s[1]==s[8]&&s[3]==s[10]&&s[4]==s[11]&&s[5]>='A'&&s[5]<='C'&&s[12]>='A'&&s[12]<='C'){
			cout<<"1";
			break;
		}else if(s[0]==s[7]&&s[1]==s[8]&&s[3]==s[10]&&s[4]==s[11]&&s[5]>='D'&&s[5]<='F'&&s[12]>='D'&&s[12]<='F'){
			cout<<"1";
			break;
		}else{
			cout<<"0";
			break;
		}
	}
	for(int i=0;i<=l-1;i++){
		if(s[0]==s[7]&&s[1]==s[8]&&s[3]==s[10]&&s[4]==s[11]&&s[5]>='A'&&s[5]<='C'&&s[12]>='A'&&s[12]<='C'&&s[5]&&s[5]!=s[12]){
			if(s[5]-1==s[12]){
				cout<<"1";
				break;
			}else if(s[5]+1==s[12]){
					cout<<"1";
					break;
			}else{
				cout<<"0";
				break;
			}
		}else if(s[0]==s[7]&&s[1]==s[8]&&s[3]==s[10]&&s[4]==s[11]&&s[5]>='D'&&s[5]<='F'&&s[12]>='D'&&s[12]<='F'&&s[5]&&s[5]!=s[12]){
			if(s[5]-1==s[12]){
				cout<<"1";
				break;
			}else if(s[5]+1==s[12]){
				cout<<"1";
				break;
			}
		}else{
			cout<<"0";
			break;
		}
	}
	return 0;
} 
