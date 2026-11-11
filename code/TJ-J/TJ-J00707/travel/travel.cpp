
#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int o,l;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>> c2>> s2;
    
    if(c1==c2){
    	l=1;
    	cout<<"1";
	}
	else{
		cout<<"0";
	}
	//1
    for(int i=0;i<2;i++){
    	if(s1[i]==s2[i]&&l==1){
    		o=1;
		}
		else{
			break;
		}
	}
	if(o==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	//2
	if(('A'<=s1[3]<='C'&&'A'<=s2[3]<='C'&&o==1)||('D'<=s1[3]<='E'&&'D'<=s2[3]<='E'&&o==1)){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	//3
	if(((s1[3]=='A'&&s2[3]=='B')||(s1[3]=='B'&&s2[3]=='A')||(s1[3]=='B'&&s2[3]=='C')||(s1[3]=='C'&&s2[3]=='B'))||((s1[3]=='D'&&s2[3]=='E')||(s1[3]=='E'&&s2[3]=='D'))){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
} 
