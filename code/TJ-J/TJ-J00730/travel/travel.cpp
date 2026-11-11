#include<bits/stdc++.h>
using namespace std;
string s1;
string s2;
char a1[3];
char a2[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>s1;
	for(int i=0;i<3;i++)cin>>a1[i];
	cin>>s2;
	for(int i=0;i<3;i++)cin>>a2[i];
	
	bool one=(s1==s2);
	bool two=(a1[0]+a1[1]==a2[0]+a2[1]);
	bool three=false;
	bool four=false;
	if(a1[2]=='E'){
		if(a2[2]=='F'){
			three=true;
			four=true;
		}
	}else if(a1[2]=='F'){
		if(a2[2]=='E'){
			three=true;
			four=true;
		}
	}else if(a1[2]=='A' || a1[2]=='B' || a1[2]=='C'){
		if(a2[2]=='A' || a2[2]=='B' || a2[2]=='C'){
			three=true;
			if((a1[2]=='A'&&a2[2]=='B')||(a1[2]=='B'&&a2[2]=='C')){
				four=true;
			}else if((a2[2]=='A'&&a1[2]=='B')||(a2[2]=='B'&&a1[2]=='C')){
				four=true;
			}
		}
	}
	
	if(one){
		cout<<1;
	}else{
		cout<<0;
	}
	if(one&&two){
		cout<<1;
	}else{
		cout<<0;
	}
	if(one&&two&&three){
		cout<<1;
	}else{
		cout<<0;
	}
	if(one&&two&&three&&four){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
