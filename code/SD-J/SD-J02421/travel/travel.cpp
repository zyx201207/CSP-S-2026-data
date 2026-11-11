#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c1=0,c2=0;
	string s1,s2;
	char h1,h2;
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<1;
		for(int i=1;i<=s1.size();i++){
		if(s1[i]>='1'&&s1[i]<'9'){
			if(s1[i]!=s2[i]){
				c1=1;
			}
		}
		if(s1[i]>='A'&&s1[i]<='C'){
			if(s2[i]>='A'&&s2[i]<='C'){
				c2=1;
				
				if(s1[i]=='A'&&s2[i]=='C'){
					c2=3;
					
				}
				if(s1[i]=='C'&&s2[i]=='A'){
					c2=3;
					
				}
			}
			
		}
		else if(s1[i]>='D'&&s1[i]<='E'){
			if(s2[i]>='D'&&s2[i]<='E'){
				
				c2=2;
			}
		}
	}
	if(c1==1){
		cout<<0<<0<<0;
	}
	else{
		cout<<1;
		if(c2==0){
		cout<<0<<0;
	}
	if(c2==2){
		cout<<1<<1<<"c1";
	}
	if(c2==1){
		cout<<1;
		
		
			cout<<1;
		
	}
	if(c2==3){
		cout<<1<<0;
	}
	}
	
	}
	else{
		cout<<0<<0<<0<<0;
	}
	
} 
