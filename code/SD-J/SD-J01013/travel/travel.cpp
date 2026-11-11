#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	//problem1
	bool flag1=true;
	for(int i=0;i<c1.size();i++){
		if(c1[i]!=c2[i]){
			flag1=false;
		}
	}
	if(!flag1){
		cout<<0;
	}else{
		cout<<1;
	}
	
	//problem2
	int flag2=true;
	if(!flag1){
		cout<<0;
	}else{
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				flag2=false;
				break;
			}
		}
		if(!flag2){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	
	//problem3
	bool flag3=true;
	if(!flag2||!flag1){
		cout<<0;
	}else{
		if(s1[2]=='A'){
			if(s2[2]=='B'||s2[2]=='C'){
				cout<<1; 
			}else{
				cout<<0;
				flag3=false;
			}
		}else if(s1[2]=='B'){
			if(s2[2]=='A'||s2[2]=='C'){
				cout<<1; 
			}else{
				cout<<0;
				flag3=false;
			}
		}else if(s1[2]=='C'){
			if(s2[2]=='B'||s2[2]=='A'){
				cout<<1; 
			}else{
				cout<<0;
				flag3=false;
			}
		}else if(s1[2]=='D'){
			if(s2[2]=='E'){
				cout<<1; 
			}else{
				cout<<0;
				flag3=false;
			}
		}else{
			if(s2[2]=='D'){
				cout<<1; 
			}else{
				cout<<0;
				flag3=false;
			}
		}
	}
	
	//problem4
	if(!flag3||!flag2||!flag1){
		cout<<0;
	}else{
		if(s1[2]=='A'){
			if(s2[2]=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(s1[2]=='B'){
			if(s2[2]=='A'||s2[2]=='C'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(s1[2]=='C'){
			if(s2[2]=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(s1[2]=='D'){
			if(s2[2]=='E'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			if(s2[2]=='D'){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}
	
	
	return 0;
}
