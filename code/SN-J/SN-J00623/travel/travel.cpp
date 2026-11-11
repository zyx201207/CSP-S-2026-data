#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string s1,s2,t1,t2;
int check1(char x,char y){
	if(x=='A'&&y=='D')
		return 0;
	if(x=='D'&&y=='A')
		return 0;
	if(x=='A'&&y=='F')
		return 0;
	if(x=='F'&&y=='A')
		return 0;
	if(x=='B'&&y=='D')
		return 0;
	if(x=='D'&&y=='B')
		return 0;
	if(x=='B'&&y=='F')
		return 0;
	if(x=='F'&&y=='B')
		return 0;
	if(x=='C'&&y=='D')
		return 0;
	if(x=='D'&&y=='C')
		return 0;
	if(x=='C'&&y=='F')
		return 0;
	if(x=='F'&&y=='C')
		return 0;
	return 1;
}
int check(char x,char y){
	if(x=='A'){
		if(y=='B')
			return 1;
		else
			return 0;
	}
	if(x=='B'){
		if(y=='A'||y=='C')
			return 1;
		else
			return 0;
	}
	if(x=='C'){
		if(y=='B')
			return 1;
		else
			return 0;
	}
	if(x=='D'){
		if(y=='F')
			return 1;
		else
			return 0;
	}
	if(x=='F'){
		if(y=='D')
			return 1;
		else
			return 0;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>t1>>t2;
	if(s1==t1){
		cout<<1;
		if(t2[0]+t2[1]==s2[0]+s2[1]){
			cout<<1;
			if(check1(s2[2],t2[2])){
				cout<<1;
				if(check(s2[2],t2[2]))
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0; 
} 
