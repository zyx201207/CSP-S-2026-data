#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string a1,a2,s1,s2;
	cin>>a1>>a2>>s1>>s2;
	if(a1==s1){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2[0]+a2[1]==s2[0]+s2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(a2[2]-'A'<=2 && s2[2]-'A'<=2){
		cout<<"1";
	}else if(a2[2]-'A'>2 && s2[2]-'A'>2){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(a2[2]-'A'+1==s2[2]-'A' || a2[2]-'A'-1==s2[2]-'A'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
