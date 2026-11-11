#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s2[5],s1[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out ","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	int a=s1[0]*10+s1[1];
	int b=s2[0]*10+s2[1];
	if(a==b){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C')){
		cout<<"1";
	}else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
		cout<<"1";
	}else if(s1[2]=='C'&&(s2[2]=='B'||s2[2]=='A')){
		cout<<"1";
	}else if(s1[2]=='D'&&s2[2]=='F'){
		cout<<"11";
		return 0;
	}else if(s1[2]=='F'&&s2[2]=='D'){
		cout<<"11";
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
} 
