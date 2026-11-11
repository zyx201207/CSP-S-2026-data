#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>s1>>c1>>s2>>c2;
	bool q1=0,q2=0,q3=0,q4=0;
	if(s1==s2){
		q1=1;
	}
	if(q1&&c1[0]==c2[0]&&c1[1]==c2[1]){
		q2=1;
	}
	bool op1,op2;
	if(c1[2]=='D'||c1[2]=='F'){
		op1=0;
	}else{
		op1=1;
	}
	if(c2[2]=='D'||c2[2]=='F'){
		op2=0;
	}else{
		op2=1;
	}
	if(q2&&op1==op2){
		q3=1;
	}
	if(q3&&abs(c1[2]-c2[2])==1){
		q4=1;
	}
	cout<<q1<<q2<<q3<<q4;
	return 0;
}