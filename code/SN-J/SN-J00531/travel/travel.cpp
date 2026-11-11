#include<iostream>
using namespace std;
int main(){
	freopen("travel.cpp","r",stdin);
	freopen("travel.cpp","w",stdout);
	int c1,c2;
	char s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1+1==s2||s1+2==s2){
		cout<<"1";
	}else if(s1+3==s2||s1+4==s2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1<='01C'&&s2<='01C'){
		cout<<"1";
	}else if(s1<='02C'&&s2<='02C'){
		cout<<"1";
	}else if(s1<='03C'&&s2<='03C'){
		cout<<"1";
	}else if(s1<='04C'&&s2<='04C'){
		cout<<"1";
	}else if(s1<='05C'&&s2<='05C'){
		cout<<"1";
	}else if(s1<='06C'&&s2<='06C'){
		cout<<"1";
	}else if(s1<='07C'&&s2<='07C'){
		cout<<"1";
	}else if(s1<='08C'&&s2<='08C'){
		cout<<"1";
	}else if(s1<='09C'&&s2<='09C'){
		cout<<"1";
	}else if(s1<='10C'&&s2<='10C'){
		cout<<"1";
	}else if(s1<='11C'&&s2<='11C'){
		cout<<"1";
	}else if(s1<='12C'&&s2<='12C'){
		cout<<"1";
	}else if(s1<='13C'&&s2<='13C'){
		cout<<"1";
	}else if(s1<='14C'&&s2<='14C'){
		cout<<"1";
	}else if(s1<='15C'&&s2<='15C'){
		cout<<"1";
	}else if(s1<='16C'&&s2<='16C'){
		cout<<"1";
	}else if(s1<='17C'&&s2<='17C'){
		cout<<"1";
	}else if(s1<='01F'&&s1>='01D'){
		cout<<"1";
	}else if(s1<='02F'&&s1>='02D'){
		cout<<"1";
	}else if(s1<='03F'&&s1>='03D'){
		cout<<"1";
	}else if(s1<='04F'&&s1>='04D'){
		cout<<"1";
	}else if(s1<='05F'&&s1>='05D'){
		cout<<"1";
	}else if(s1<='06F'&&s1>='06D'){
		cout<<"1";
	}else if(s1<='07F'&&s1>='07D'){
		cout<<"1";
	}else if(s1<='08F'&&s1>='08D'){
		cout<<"1";
	}else if(s1<='09F'&&s1>='09D'){
		cout<<"1";
	}else if(s1<='10F'&&s1>='10D'){
		cout<<"1";
	}else if(s1<='11F'&&s1>='11D'){
		cout<<"1";
	}else if(s1<='12F'&&s1>='12D'){
		cout<<"1";
	}else if(s1<='13F'&&s1>='13D'){
		cout<<"1";
	}else if(s1<='14F'&&s1>='14D'){
		cout<<"1";
	}else if(s1<='15F'&&s1>='15D'){
		cout<<"1";
	}else if(s1<='16F'&&s1>='16D'){
		cout<<"1";
	}else if(s1<='17F'&&s1>='17D'){
		cout<<"1";
    }else{
    	cout<<"0";
	}
	if(s1+'1'==s2||s1-'1'==s2){
		cout<<"1";
	}
	return 0;
}
