#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10,M=1e3+10;
string s1,s2,s3,s4;
int as=0,bs=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		printf("1");
	}
	else{
		printf("0");
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&s1==s3){
		printf("1");
	}
	else{
		printf("0");
	}
	char c_1,c_2;
	c_1=s2[2];
	c_2=s4[2];
	bool ff=((c_1<='C'&&c_2<='C')||(c_1>='D'&&c_2>='D'))&&s2[0]==s4[0]&&s2[1]==s4[1]&&s1==s3;
	//cerr<<ff<<"\n"; 
	if(ff){
		printf("1");
	}
	else{
		printf("0");
	}
	if(ff==1&&(abs(int(c_1-c_2))==1)||(c_1=='D'&&c_2=='F')||(c_1=='F'&&c_2=='D')&&s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]){
		printf("1");
	}
	else{
		printf("0");
	}
	return 0;
}
//02 02B 02 01A
