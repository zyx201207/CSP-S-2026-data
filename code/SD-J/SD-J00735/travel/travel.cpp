#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=true,b=true,c=true,d=true;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i])a=false;
	}
	if(a){
		cout<<"1";
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i])b=false;
		}
		if(b){
			cout<<"1";
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]!='A'&&s2[2]!='B'&&s2[2]!='C')c=false;
			}
			else if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]!='D'&&s2[2]!='F')c=false;
			}
			if(c){
				cout<<"1";
				if(s1[2]=='A'&&s2[2]!='B')d=false;
				else if(s1[2]=='B'&&(s2[2]!='A'&&s2[2]!='C'))d=false;
				else if(s1[2]=='C'&&s2[2]!='B')d=false;
				else if(s1[2]=='D'&&s2[2]!='F')d=false;
				else if(s1[2]=='F'&&s2[2]!='D')d=false;
				if(d){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
