#include <bits/stdc++.h>
using namespace std;
char c1[2],c2[2],s1[3],s2[3];
int main() {
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	for(int i=0; i<=1; i++)cin>>c1[i];

	for(int i=0; i<=2; i++)cin>>s1[i];

	for(int i=0; i<=1; i++)cin>>c2[i];

	for(int i=0; i<=2; i++)cin>>s2[i];

    if(s1[2]=='F'){
    	s1[2]='E';
	} 
	if(s2[2]=='F'){
    	s2[2]='E';
	}
	int flag=0;
	for(int i=0; i<=1; i++) {
		if(c1[i]!=c2[i]) {
			flag=1;
		}
	}
	if(flag==1) {
		cout<<"0000";
		return 0;
	} else {
		cout<<"1";
	}
	flag=0;
	for(int i=0; i<=1; i++) {
		if(s1[i]!=s2[i]) {
			flag=1;
		}
	}
	if(flag==1){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";
	}
	
	if((s1[2]-'A')<=2&&(s2[2]-'A')<=2){
		cout<<"1";
	}else if((s1[2]-'A')>2&&(s2[2]-'A')>2){
		cout<<"1";
	}else {
		cout<<"00";
		return 0;
	}
	
	if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	return 0;
}
