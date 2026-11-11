#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	if(s[0]!=s[7]||s[1]!=s[8]){
		cout<<"0000";
		return 0;
	}else {
		cout<<"1";
		if(s[3]!=s[10]||s[4]!=s[11]){
			cout<<"000";
			return 0;
		}else {
			cout<<"1";
			if((s[5]>='D'&&s[12]>='D')||(s[5]<='C'&&s[12]<='C')){
				cout<<"1";
				if(abs(int(s[5]-s[12]))<=1){
					cout<<"1";
					return 0;
				}else {
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}
	}
	return 0;
}
