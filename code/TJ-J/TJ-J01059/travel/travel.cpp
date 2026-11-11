#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1;
	else {cout<<"0000";return 0;}
	int n=s2.length();
	int p=0;
	for(int i=0;i<n;i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			if(s2[i]!=s4[i]){
				p=2;
				break;
			}
		}
	}
	if(!p){
		cout<<1;
	}
	else{
		cout<<0;
	}
	int o=0;
	if(p){
		cout<<0;
	}
	else{
		char r=s2[n-1];
		char x=s4[n-1];
		if(r>='A'&&r<='C'){
			if(x>='A'&&x<='C'){
				cout<<1;
			}
			else{
				o=1;
				cout<<0;
			}
		}
		else if(r=='F'&&x=='D'||r=='D'&&x=='F'){
			cout<<1;
		}
		else{
			o=1;
			cout<<0;
		}
	}
	if(p||o){
		cout<<0;
	}
	else{
		char r=s2[n-1];
		char x=s4[n-1];
		if(r=='F'||r=='D'&&x=='F'||x=='D'){
			if(r=='F'&&x=='D'||r=='D'&&x=='F'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		
		else if(r>='A'&&r<='C'&&x>='A'&&x<='C'){
			if(abs(r-x)==1){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	}
	return 0;
}
