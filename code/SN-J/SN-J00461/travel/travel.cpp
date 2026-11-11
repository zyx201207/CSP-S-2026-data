#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<10;i++){
		cin>>s[i];
	}
	if(s[0]==s[5]&&s[1]==s[6]){
		if(s[2]==s[7]&&s[3]==s[8]){
			if(s[4]+s[9]<=132||s[4]+s[9]==138){
				if(s[4]+s[9]!=132||s[4]+s[9]==138){
					cout<<1111;
				}else{
					cout<<1110;
				}
			}else{
				cout<<1100;
			}
		}else{
			cout<<1000;
		}
	}else{
		cout<<0000;
	}
	return 0;
}
