#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string num1,c1,s1,c2,s2,tout="0000";
	getline(cin,num1);
	c1[0]=num1[0];
	c1[1]=num1[1];
	s1[0]=num1[3];
	s1[1]=num1[4];              
	s1[2]=num1[5];
	c2[0]=num1[7];
	c2[1]=num1[8];
	s2[0]=num1[10];
	s2[1]=num1[11];
	s2[2]=num1[12];
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
	tout[0]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			tout[1]='1';
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
			tout[2]='1';
			if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
				tout[3]='1';
			}
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<tout[i];
	}
	return 0;
} 
