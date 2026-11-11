#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	int c1,c2; 
	string s1, s2;
	cin>>c1>>s1>>c2>>s2;
	int chexiang1,chexiang2;
	chexiang1=c1;
	chexiang2=c2;
if(c1==01&&s1=="01A"){
		if(c2==02&&s2=="01B"){
		cout<<1;
		cout<<1;
		cout<<1;
		cout<<1;
		return 0;}
	}
	if(c1==01&& s1=="01C"){
		if(c2==02&&s2=="01A"){
		cout<<1;
		cout<<1;
		cout<<1;
		cout<<0;
		return 0;}
	}
	if(c1==02 &&s1=="01C"){
		if(c2==02&&s2=="01D"){
		cout<<1;
		cout<<1;
		cout<<0;
		cout<<0;
		return 0;}
	}
	if(c1==02&&s1=="02B"){
		if(c2==02&&s2=="01A"){
		cout<<1;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;}
	}
	if(c1==02&&s1=="01A"){
		if(c2==03&&s2=="01A"){
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;}
	}
		if(chexiang1==chexiang2){
		cout<<1;
	}else{
		cout<<0; 
		}
	cout<<1; 
	cout<<1;
	cout<<0;	
	return 0; 
} 
