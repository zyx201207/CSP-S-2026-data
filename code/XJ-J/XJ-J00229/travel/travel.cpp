#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r"stdin);
	freopen("travel.out","w"stdout);
	int c1,c2,a,b;
	string s1,s2,ss,sss;
	cin>>c1>>s1>>c2>>s2;
	a=s1[0]+'0'*10+s1[1]+'0'; 
	b=s2[0]+'0'*10+s2[1]+'0';
	if(c1==c2){
		cout<<"1";
		
	}
	else{
		cout<<"0";
	}
	if(a==b){
		cout<<"1";
		
	}
	else{
		cout<<"0";
	}
	ss=s1[s1.length()-1];
	sss=s2[s2.length()-1];
	if(ss=='A'||ss=='B'||ss=='C'){
		if(a==b&&(ss==sss+=1||ss==sss-=1)){
			cout<<"1";
	}
		else if(ss=='D'||ss=='F'){
			if(a==b&&(ss==sss+=2||ss==sss-=2)){
				cout<<"1";
			}
		}
	}
	else{
		cout<<"0";
	}
	return 0;
}
