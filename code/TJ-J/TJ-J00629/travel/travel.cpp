#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	int num1,num2;
	char zuo1,zuo2;
	num1=(s1[0]-'0')*10+s1[1]-'0';
	num2=(s2[0]-'0')*10+s2[1]-'0';
	zuo1=s1[2];
	zuo2=s2[2];
	if(zuo1=='F'){
		zuo1='E';
	}
	if(zuo2=='F'){
		zuo2='E';
	}
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		
	}
	else if(num1!=num2){
		cout<<1<<0<<0<<0;
	}
	else if(zuo1<'D'&&zuo2<'D'||zuo1>='D'&&zuo2>='D'){
		cout<<1<<1<<1;
		if(abs(zuo1-zuo2)==1){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<1<<1<<0<<0;
	return 0;
}
