#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;//c车厢，s座号
	int d;
	cin>>c1>>s1>>c2>>s2;
	//是否同一节
	for(int i=0;i<2;i++){
		if(c1[i]==c2[i]){
			d=1;
		}else{
			d=0;
			break;
		}
	} 
	if(d==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	//是否同一排
	if(d==1){
		for(int i=0;i<2;i++){
			if(s1[i]==s2[i]){
				d=1;
			}else{
				d=0;
				break;
			}
		}
	}else{
		d=0;
	} 
	if(d==1){
		cout<<"1";
	}else{
		cout<<"0";
	}	
	//是否同一侧
	if(d==1){
		if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='C'||s1[2]=='B'||s2[2]=='A')){
			cout<<"0";
			d=0;
		}else{
		if((s2[2]=='D'||s1[2]=='F')&&(s1[2]=='C'||s1[2]=='B'||s2[2]=='A')){
			cout<<"0";
			d=0;
		}else{
			cout<<"1";
			d=1; 
		}		
		}
	}else{
		cout<<"0";
	}
	//是否相邻 
	if(d==1){
		if(s1[2]-1==s2[2]||s1[2]+1==s2[2]){
			cout<<"1";
		}else{
			cout<<"0"; 
		}		
	}else{
		cout<<"0";
	}
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
