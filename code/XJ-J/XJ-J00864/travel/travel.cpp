#include <bits/stdc++.h>

using namespace std;
	string str;
	int che1,che2,pai1,pai2;
	char zuo1,zuo2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,str);
	for(int i=0;i<=1;i++){
		che1=che1*10+str[i]-'0';
	}
	for(int i=3;i<=4;i++){
		pai1=pai1*10+str[i]-'0';
	}	
	zuo1=str[5];
	
	for(int i=7;i<=8;i++){
		che2=che2*10+str[i]-'0';
	}	
	for(int i=10;i<=11;i++){
		pai2=pai2*10+str[i]-'0';
	}
	zuo2=str[12];
	
	if(che1==che2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(pai1==pai2){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	
	if(zuo1=='D'||zuo1=='F'){
		if(zuo2=='D'||zuo2=='F'){
			cout<<1;
		}else{
			cout<<0<<0;
			return 0;
		}
	}else{
		if(zuo2!='D'){
			if(zuo2!='F'){
				cout<<1;
			}
		}else{
			cout<<0<<0;
			return 0;
		}
	}
	if(zuo1=='A'){
		if(zuo2=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(zuo1=='B'){
		if(zuo2=='A'||zuo2=='C'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(zuo1=='C'){
		if(zuo2=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(zuo1=='D'){
		if(zuo2=='F'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(zuo1=='F'){
		if(zuo2=='D'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}