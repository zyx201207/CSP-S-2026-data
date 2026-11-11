#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,a1,b1;
	cin>>a>>a1>>b>>b1;
	bool flag=0;
	if(a!=b) cout<<"0000";
	else{
		cout<<"1";
		if(a1[0]==b1[0]&&a1[1]==b1[1]){
			cout<<"1";	
			flag=1;
		} else cout<<"0";
		
		if(flag){
			if((a1[2]=='C'||a1[2]=='B'||a1[2]=='A')&&(b1[2]=='C'||b1[2]=='B'||b1[2]=='A')){
				cout<<"1";
			}else if((b1[2]=='F'||b1[2]=='D')&&(a1[2]=='F'||a1[2]=='D')){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else cout<<"0";
		if(flag){
			if((b1[2]=='F'||b1[2]=='D')&&(a1[2]=='F'||a1[2]=='D')) cout<<"1";
			else if((a1[2]=='C'||a1[2]=='B'||a1[2]=='A')&&(b1[2]=='C'||b1[2]=='B'||b1[2]=='A')){
				if(a1[2]=='B'||b1[2]=='B') cout<<"1";
				else cout<<"0";
			}else{
				cout<<"0";
			}
		}else cout<<"0";
		
	}
	return 0;
} 
