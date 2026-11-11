#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,st="";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)st+="1";
	else st+="0";
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		st+="1";
	}else st+="0";
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
			st+="1";
		}else st+="0";
	}else st+="0";
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
			if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
				st+="1";
			}else st+="0";
		}else st+="0";
	}else st+="0";
	cout<<st;
	return 0;
}