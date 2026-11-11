#include<bits/stdc++.h>
#define IOSO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
#define QwQ return 0;
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	IOSO;
	string s,s1,t,t1;
	cin>>s>>s1>>t>>t1;
	int flag1=0,flag2=0,flag3=0;
	if(s==t){
		flag1=1;
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(flag1&&s1[0]==t1[0]&&s1[1]==t1[1]){
		cout<<"1";
		flag2=1;
	}else{
		cout<<"0";
	}
	int num1=(s1[2]-'A'+1),num2=(t1[2]-'A'+1);
	if((num1>3&&num2>3&&flag1&&flag2)||(num1<=3&&num2<=3&&flag1&&flag2)){
		cout<<"1";
		flag3=1;
	}else{
		cout<<"0";
	}
	if(flag1&&flag2&&flag3&&(abs(num1-num2)<=1||(num1==4&&num2==6)||(num1==6&&num2==4))){
		if(num1==3&&num2==4){
			cout<<"0";
		}else if(num1==4&&num2==3){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}else{
		cout<<"0";
	}
	QwQ;
}