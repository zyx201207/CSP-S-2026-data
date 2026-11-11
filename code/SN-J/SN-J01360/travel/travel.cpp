#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[4],s1[4],c2[4],s2[4];
	for(int i=1;i<=2;i++){
		cin>>c1[i];
	}
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	for(int i=1;i<=2;i++){
		cin>>c2[i];
	}
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		cout<<"1";
		if(s1[1]==s2[1]){
			cout<<"1";
			if(s1[2]<='C'&&s2[2]<='C'||s1[2]<='E'&&s2[2]<='E'){
				cout<<"1";
				if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='E'&&s2[2]=='D'||s1[2]=='E'&&s2[2]=='E'){
					cout<<"1";
				}else{
					cout<<"0";
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
