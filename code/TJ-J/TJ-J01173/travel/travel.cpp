#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	string c1;
	string c2;
	string s1;
	string s2;
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
				cout<<1;
				if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'){
				for(int i=0;i<2;i++){
					cout<<1;
				}
			}
			else{
				for(int i=0;i<2;i++){
					cout<<0;
				}
			}
		}
		else{
			for(int i=0;i<3;i++){
				cout<<0;
			}
		}
	}
	else{
			
		for(int i=0;i<4;i++){
			cout<<0;
		}
		
	}
	return 0;
	
} 
