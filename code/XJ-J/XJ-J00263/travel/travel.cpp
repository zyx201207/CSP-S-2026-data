#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string zuo1={},wei1={},zuo2={},wei2={};
	bool f=false;
	cin>>zuo1>>wei1>>zuo2>>wei2;
	if(zuo1==zuo2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	int len=wei1.length();
	int len2=wei2.length();
	if(wei1[len-2]==wei2[len2-2]&&wei1[len-1]==wei2[len2-1]){
		cout<<"0";
	}
	else{
		cout<<"1";
	}
	if(wei1[len-1]>='A'&&wei1[len-1]<='C'||wei1[len-1]>='D'&&wei1[len-1]<='F'||wei2[len-1]>='A'&&wei2[len-1]<='C'||wei2[len-1]>='D'&&wei2[len-1]<='F'){
			cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(wei1[len]-'A'==wei2[len2]||wei1[len]+'A'==wei2[len2]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}