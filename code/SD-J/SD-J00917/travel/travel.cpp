#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
bool op1,op2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	} 
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int m1=(s1[0]-'0')*10+(s1[1]-'0');
	int m2=(s2[0]-'0')*10+(s2[1]-'0');
	//cout<<m1<<" "<<m2;
	if(m1==m2){
		cout<<1; 
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	
	
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		op1=0;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		op2=0;
	}
	if(s1[2]=='D'||s1[2]=='F'){
		op1=1;
	}
	if(s2[2]=='D'||s2[2]=='F'){
		op2=1;
	}
	
	
	if(op1==op2){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(op1==1&&op2==1){
		cout<<1;
	}
	else{
		if(op1==0&&op2==0&&( (s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C'))){
			cout<<0;
		}
		else{
			cout<<1;
		}
		
	}
	return 0;
}
