#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	a2=a2+char(a1[0])+a1[1];
	b2=b2+char(b1[0])+b1[1];
	if(a!=b){
		cout<<"0000";
	}else if(a2!=b2){
		cout<<"1000";
	}else if(((a1[2]=='A'||a1[2]=='C'||a1[2]=='B')&&(b1[2]=='D'||b1[2]=='F'))||((b1[2]=='A'||b1[2]=='C'||b1[2]=='B')&&(a1[2]=='D'||a1[2]=='F'))){
		cout<<"1100";
	}else if(abs(a1[2]-b1[2])>1){
		cout<<"1110";
	}else if(a1[2]!='C'&&b1[2]!='D'){
		cout<<"1111";
	}
	return 0;
} 
