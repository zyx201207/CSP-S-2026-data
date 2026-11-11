#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char c_1[4]={'A','B','C'};
char c_2[3]={'D','E'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool b1,b2,b3,b4;
	bool bA=0,bB=0,bC=0,bD=0;
	for(int i=0;i<3;i++){
		if(s1[2]==c_1[i]) bA=1;
		if(s2[2]==c_1[i]) bB=1;
	}
	for(int i=0;i<2;i++){
		if(s1[2]==c_2[i]) bC=1;
		if(s2[2]==c_2[i]) bD=1;
	}
	b1=c1==c2;
	b2=s1[0]==s2[0]&&s1[1]==s2[1];
	b3=(bA&&bB)||(bC&&bD);
	b4=s1[2]+1==s2[2]||s1[2]-1==s2[2];
	if(!b1) cout<<"0000";
	else if(!b2) cout<<"1000";
	else if(!b3) cout<<"1100";
	else if(!b4) cout<<"1110";
	else cout<<"1111";
	return 0;
} 
