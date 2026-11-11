#include<bits/stdc++.h>
using namespace std;
string a,b,s,t;
int zh(char p){
	if(p=='A'||p=='B'||p=='C')return 1;
	return 0;
}int zq(char p){
	if(p=='A')return 1;
	else if(p=='B')return 2;
	else if(p=='C')return 3;
	else if(p=='D')return 4;
	else return 5;
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>t;
	if(a!=b){
		cout<<"0000";
		return 0;
	}cout<<"1";
	if(s[0]!=t[0]||s[1]!=t[1]){
		cout<<"000";
		return 0;
	}cout<<"1";
	if(zh(s[2])!=zh(t[2])){
		cout<<"00";
		return 0;
	}cout<<"1";
	if(abs(zq(s[2])-zq(t[2]))!=1)cout<<"0";
	else cout<<"1";
	return 0;
}