#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string n1,n2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<=1;i++){
		n1+=s1[i];
		n2+=s2[i];
	}
	if(n1==n2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s1[2]-'0'==20&&s2[2]-'0'!=22){
		cout<<0<<0;
		return 0;
	}
	else if(s2[2]-'0'==20&&s1[2]-'0'!=22){
		cout<<0<<0;
		return 0;
	}
	else if(s1[2]-'0'==22&&s2[2]-'0'!=20){
		cout<<0<<0;
		return 0;
	}
	else if(s2[2]-'0'==22&&s1[2]-'0'!=20){
		cout<<0<<0;
		return 0;
	}
	
	cout<<1;
	
	if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
		cout<<1;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}

