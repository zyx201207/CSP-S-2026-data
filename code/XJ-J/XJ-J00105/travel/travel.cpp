#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string s4;
	int a=s1[2],b=s2[2];
	if(c1!=c2){
		s4="0000";
	}else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		s4="1000";
	}else if(s1[2]+s2[2]>'A'+'C'&&s1[2]+s2[2]!='D'+'F'){
		s4="1100";
	}else if(a+1==b||a-1==b){
		s4="1111";
	}else s4="1110";
	cout<<s4;
	return 0;
} 
