#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool ce(char c){
	if(c=='A' || c=='B' || c=='C'){
		return 0;
	}
	return 1;
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	int r1=0, r2=0, x1=0, x2=0;
	char r3, x3;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0; i<c1.size(); i++){
		r1=r1*10+c1[i]-'0';
	}
	for(int i=0; i<c2.size(); i++){
		x1=x1*10+c2[i]-'0';
	}
	if(r1!=x1){
		cout<<"0000";
		return 0;
	}for(int i=0; i<s1.size()-1; i++){
		r2=r2*10+s1[i];
	}for(int i=0; i<s2.size()-1; i++){
		x2=x2*10+s2[i];
	}
	if(r2!=x2){
		cout<<"1000";
		return 0;
	}
	r3=s1[s1.size()-1];
	x3=s2[s2.size()-1];
	if(ce(r3)!=ce(x3)){
		cout<<"1100";
		return 0;
	}
	if(abs(r3-x3)>1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
