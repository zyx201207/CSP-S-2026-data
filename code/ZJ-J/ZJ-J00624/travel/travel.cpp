#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,si1,s2,si2;
	cin>>s1>>si1>>s2>>si2;
	bool f=0,f1=0;
	if(s1.size()!=s2.size()){
		cout<<0000;
		return 0;
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			f=1;
		}
	}
	if(f==1){
		cout<<0<<0<<0<<0;
		return 0;
	}
	else cout<<1;
	f=0;
	for(int i=0;i<si1.size();i++){
		if(si1[i]>='A'&&si2[i]>='A'){
			break;
		}
		else{
			if(si1[i]!=si2[i]){
				f=1;
				break;
			}
		}
	}
	if(f==1){
		cout<<0<<0<<0;
		return 0;
	}
	else cout<<1;
	f=0;
	for(int i=0;i<si1.size();i++){
		if(si1[i]>='A'&&si2[i]>='A'){
			if(si1[i]>'C'){
				if(si2[i]<='C') f=1;
			}
			else{
				if(si2[i]>'C') f=1;
			}
		}
	}
	if(f==1){
		cout<<0<<0;
		return 0;
	} 
	else cout<<1;
	f=0;
	for(int i=0;i<si1.size();i++){
		if(si1[i]>='A'&&si2[i]>='A'){
			if(abs((si1[i]-'A')-(si2[i]-'A'))!=1){
				f=1;
			}
		}
	}
	if(f==1) cout<<0;
	else{
		cout<<1;
	}
	return 0;
}
