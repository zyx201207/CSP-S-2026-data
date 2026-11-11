#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c;
    string s;
    string b;
	int a;
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>s;
	if(a==c){
		cout<<1;
	}
	else {
		cout<<0000;
		return 0;
	}
	int num=0;
	for (int i=0;i<=1;i++){
		if(s[i]==b[i]){
			num++;
		}
	}
	if (num==2){
		cout<<1;
	}
	else {
		cout<<000;
		return 0;
	} 
	if ((s[2]=='D'&&b[2]!='F')||(s[2]=='F'&&b[2]!='D')){
		cout<<00;
		return 0;
	}
	else {
		cout<<1;
	}
	if ((s[2]=='A'&&b[2]=='B')||(s[2]=='A'&&b[2]=='C')||(s[2]=='B'&&b[2]=='A')||(s[2]=='C'&&b[2]=='B')||(s[2]=='D'&&b[2]=='F')||(s[2]=='F'&&b[2]=='D')){
		cout<<1;
	}
	else {
		cout<<0;
		return 0;
	}
	return 0;
} 
