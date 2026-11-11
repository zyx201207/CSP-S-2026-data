#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	int size=s1.size();
	if(s1==c1){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	char a=s2[0];
	char a1=s2[1];
	char a2=s2[2];
	char b=c2[0];
	char b1=c2[1];
	char b2=c2[2];
	if(a==b&&a1==b1){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	
	if((a2=='C'&&b2=='D')||(a2=='D'&&b2=='C')){
		cout<<"00";
		return 0;
	}
	else{
		cout<<"1";
	}
	
	if((a2=='D'&&b2=='F')||(b2=='D'&&a2=='F')){
		cout<<"1";
	}
	else if(a2-b2==1||b2-a2==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
	
}