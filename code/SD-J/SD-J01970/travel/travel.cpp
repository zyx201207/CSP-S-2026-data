#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	string str="";
	if(c1==c2){
		str+="1";
	}else{
		str+="0";
	}if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
		str+="1";
	}else{
		str+="0";
	}if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2&&(s1[2]<='C'&&s2[2]<='C'&&s1[2]>='A'&&s2[2]>='A'||s1[2]<='E'&&s2[2]<='E'&&s1[2]>='D'&&s2[2]>='D')){
		str+="1";
	}else{
		str+="0";
	}int ans1=s1[2]-'0';
	int ans2=s2[2]-'0';
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2&&(s1[2]<='C'&&s2[2]<='C'&&s1[2]>='A'&&s2[2]>='A'||s1[2]<='E'&&s2[2]<='E'&&s1[2]>='D'&&s2[2]>='D')&&abs(ans1-ans2)==1){
		str+="1";
	}else{
		str+="0";
	}cout<<str; 
	return 0;
}
