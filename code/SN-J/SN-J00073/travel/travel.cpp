#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<1;
		
	}
	else cout<<0;
	
	if(c1==c2){
		if(s1.substr(0,2)==s2.substr(0,2)) cout<<1;
		else cout<<0; 
	}else cout<<0;
	
	if(c1==c2){
		if(s1.substr(0,2)==s2.substr(0,2)){
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') cout<<1;
				else cout<<0;
			}else if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='D'||s2[2]=='F') cout<<1;
				else cout<<0; 
			}else cout<<0;
		}else cout<<0;
	}else cout<<0;
	
	if(c1==c2){
		if(s1.substr(0,2)==s2.substr(0,2)){
			if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s2[2]=='B'&&s1[2]=='C')) cout<<1;
			else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) cout<<1;
			else cout<<0; 
		}else cout<<0;
	}else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
