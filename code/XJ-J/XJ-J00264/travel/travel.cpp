#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	int c1,s1[10],c2,s2[10],i,a,b,j;
	cin>>c1;
	for(i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(i=0;i<3;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		cout<<"1";
	}
	else if(c1!=c2){
		cout<<"0";
	}
	for(i=0;i<3;i++){
	if(s1[i]==s2[i]){
		cout<<"1";
	}}
	for(i=0;i<=3;i++){
	else if(s1[i]!=s2[i]){
		cout<<"0";
}}
	else if(s1[3]>='A'&&s1[3]<='F'&&(s1[3]+1==s2[3]||s1[3]-1==s2[3])){
		cout<<"1";
	}
	
	else if(s1[3]>='A'&&s1[3]<='F'&&(s1[3]+1!=s2[3]||s1[3]-1!=s2[3])){
		cout<<"0";
	}
	else if((s1[3]=='D'&&s2[3]=='C')||(s1[3]=='D'&&s2[3]=='B')||(s1[3]=='D'&&s2[3]=='A')||(s1[3]=='F'&&s2[3]=='C')||(s1[3]=='F'&&s2[3]=='B')||(s1[3]=='F'&&s2[3]=='A')||(s1[3]=='C'&&s2[3]=='D')||(s1[3]=='B'&&s2[3]=='D')||(s1[3]=='A'&&s2[3]=='D')||(s1[3]=='C'&&s2[3]=='F')||(s1[3]=='B'&&s2[3]=='F')||(s1[3]=='A'&&s2[3]=='F')){
		cout<<"0";
	}
	return 0;
}