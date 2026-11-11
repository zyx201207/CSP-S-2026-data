#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	int a=0,b=0,c=0; 
	if(s1==s3){
		cout<<1;
		a=1; 
	}else{
		cout<<0;
	}
	if(s2.substr(0,2)==s4.substr(0,2)&&a==1){
		cout<<1;
		b=1;
	}else{
		cout<<0;
	}
	if(s2[2]<='C'&&a==1&&b==1){
		if(s4[2]<='C'){
			cout<<1;
			c=1;
		}else{
			cout<<0;
		}
	}else{
		if(s4[2]>='D'&&a==1&&b==1){
			cout<<1;
			c=1;
		}else{
			cout<<0;
		}
	}
	if(a==0||b==0||c==0){
		cout<<0;
	}else{
		if(abs(s2[2]-s4[2])==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
