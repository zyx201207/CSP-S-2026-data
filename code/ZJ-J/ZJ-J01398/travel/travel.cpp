#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int main(){
	cin>>a>>a1;
	cin>>b>>b1;
	if(a==b){
		cout<<'1';
		if(a1[0]==b1[0]&&a1[1]==b1[1]){
			cout<<'1';
			if(a1[2]=='F'&&b1[2]=='D'||a1[2]=='D'&&b1[2]=='F'||a1[2]=='A'&&b1[2]=='B'||a1[2]=='B'&&b1[2]=='A'||a1[2]=='B'&&b1[2]=='C'||a1[2]=='C'&&b1[2]=='B'||a1[2]=='A'&&b1[2]=='C'||a1[2]=='C'&&b1[2]=='A'){
				cout<<'1';
				if(a1[2]=='A'&&b1[2]=='C'||a1[2]=='C'&&b1[2]=='A'){
					cout<<'0';
				}else{
					cout<<'1';
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}