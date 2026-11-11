#include<bits/stdc++.h>
using namespace std;
char s1[105],s2[105],s3[105],s4[105];
int f; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	for(int i=0;i<2;i++){
		if(s1[i]!=s3[i]){
			f=1;
		}
	}
	if(f==0){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	f=0;
	for(int i=0;i<2;i++){
		if(s2[i]!=s4[i]){
			f=1;
		}
	}
	if(f==1){
		cout<<"000";
		return 0;
	}
	else{
		cout<<1;
	}
	if(s2[2]=='D'&&s4[2]=='F'||s2[2]=='A'&&s4[2]=='B'||s2[2]=='B'&&s4[2]=='C'){
		cout<<"11";
		return 0;
	}
	else if(s2[2]=='C'&&s4[2]=='D'||s2[2]=='C'&&s4[2]=='F'||s2[2]=='A'&&s4[2]=='D'||s2[2]=='A'&&s4[2]=='F'||s2[2]=='B'&&s4[2]=='D'||s2[2]=='B'&&s4[2]=='F'){
		cout<<"00";
		return 0;
	}
	else{
		cout<<"10";
	}
	return 0;
}

