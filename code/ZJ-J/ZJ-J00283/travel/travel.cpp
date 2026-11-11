#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
string s;
string sz,sw,sz1,sw1;
ll ans,ans1,ans2;
string si,si1;
char zf,zf1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(!ans){
			if(s[i]==' ') ans=1;
			else sz+=s[i];
		}else if(!ans1){
			if(s[i]==' ') ans1=1;
			else sw+=s[i];
		}else if(!ans2){
			if(s[i]==' ') ans2=1;
			else sz1+=s[i];
		}else sw1+=s[i];
	}
	for(int i=0;i<sw.size();i++){
		if(i<sw.size()-1) si+=sw[i];
		else zf+=sw[i];
	}for(int i=0;i<sw1.size();i++){
		if(i<sw1.size()-1) si1+=sw1[i];
		else zf1+=sw1[i];
	}
	if(sz==sz1){
		cout<<1;
		if(si==si1){
			cout<<1;
			if((zf>='A'&&zf<='C'&&zf1>='A'&&zf1<='C')||(zf=='D'&&zf1=='F')||(zf=='F'&&zf1=='D')){
				cout<<1;
				if((zf=='A'&&zf1=='B')||(zf=='B'&&zf1=='A')||(zf=='B'&&zf1=='C')||(zf=='C'&&zf1=='B')||(zf=='D'&&zf1=='F')||(zf=='F'&&zf1=='D')) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
	return 0;
}
