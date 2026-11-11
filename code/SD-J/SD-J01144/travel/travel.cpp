#include<bits/stdc++.h>
using namespace std;
struct node{
	int c;
	string s;
}a,b;
int f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.c>>a.s>>b.c>>b.s;
	if(a.c==b.c){
		cout<<1;
	}else{
		cout<<0;
		f=1;
	}
	if(a.s[0]==b.s[0]&&a.s[1]==b.s[1]&&f==0){
		cout<<1;
	}else{
		cout<<0;
		f=1;
	}
	if((a.s[2]<='C'&&b.s[2]<='C')||(a.s[2]>='D'&&b.s[2]>='D')){
		if(f==1){
			cout<<0;
		}else{
			cout<<1;
		}
	}else{
		cout<<0;
	}
	if((a.s[2]=='C'&&b.s[2]=='D')||(a.s[2]=='D'&&b.s[2]=='C')||(a.s[2]==b.s[2])){
		cout<<0;
		return 0;
	}
	if(abs(a.s[2]-b.s[2])==1&&a.s[0]==b.s[0]&&a.s[1]==b.s[1]){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
