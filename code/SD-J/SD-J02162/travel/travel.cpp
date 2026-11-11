#include<bits/stdc++.h>
using namespace std;

bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		f1=1;
	}
	string str="",str1="";
	str=str+s2[0];
	str=str+s2[1];
	str1=str1+s4[0];
	str1=str1+s4[1];
	if(str==str1){
		f2=1;
	}
	if(f2==1&&s2[2]>='D'&&s4[2]>='D'||f2==1&&s2[2]<='C'&&s4[2]<='C'){
		f3=1;
	}
	if(s2[2]+1==s4[2]&&f2==1&&s2[2]!='C'||s2[2]-1==s4[2]&&f2==1&&s2[2]!='D'||f2==1&&s2[2]=='D'&&s4[2]=='F'||f2==1&&s2[2]=='F'&&s4[2]=='D'){
		f4=1;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}

