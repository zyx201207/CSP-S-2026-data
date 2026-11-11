#include<bits/stdc++.h>
using namespace std;
char s1[4],s2[4],c1[3],c2[3];

int main(){
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
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
		cout<<"1";
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			cout<<"1";
			if(s1[3]=='A'||s1[3]=='B'||s1[3]=='C'){
				if(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'){
					cout<<"1";
					if(s1[3]=='A'&&s2[3]=='B'){
						cout<<"1";
					}
					else if(s1[3]=='B'&&s2[3]=='C'){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
				else{
					cout<<"0"<<"0";
				}
			}
			else{
				if(s2[3]=='D'||s2[3]=='F'){
					cout<<"1"<<"1";
				}
				else{
					cout<<"0"<<"0";
				}
			}
		}
		else{
			cout<<"0"<<"0"<<"0";
		}
	}
	else{
		cout<<"0"<<"0"<<"0"<<"0";
	}
	return 0;
}
