#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int op1,op2,op3,op4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		op1=1;
	}else{
		op1=0;
	}
	if(op1==1){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			op2=1;
		}else{
			op2=0;
		}
	}
	
	if(op1==1&&op2==1){
		if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='E'||s1[2]=='F')&&(s2[2]=='E'||s2[2]=='F'))){
			op3=1;
		}else{
			op3=0;
		}
	}
	if(op1==1&&op2==1&&op3==1){
		if(((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A'))||((s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B'))||((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
			op4=1;
		}else{
			op4=0;
		}
	}
	
	cout<<op1<<op2<<op3<<op4;
	return 0;
}