#include<bits/stdc++.h>
using namespace std;
string cr,cx;
string sr,sx;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	int ccr=0,ccf=0;
	int lcr=cr.length(),lcx=cx.length();
	int lsr=sr.length(),lsx=sx.length();
	for(int i=0;i<lcr;i++){
		int k=cr[i]-'0';
		ccr=ccr*10+k;
	}
	for(int i=0;i<lcx;i++){
		int k=cx[i]-'0';
		ccf=ccf*10+k;
	}
	bool flag=0;
	if(ccf==ccr){
		cout<<1;
		flag=1;
	}else{
		cout<<0;
		flag=0;
	}
	int pr=0,px=0;
	for(int i=0;i<lsr-1;i++){
		int k=sr[i]-'0';
		pr=pr*10+k;
	}
	for(int i=0;i<lsx-1;i++){
		int k=sx[i]-'0';
		px=px*10+k;
	}
	if(px==pr&&flag){
		cout<<1;
		flag=1;
	}else{
		cout<<0;
		flag=0;
	}
	char r=sr[2],x=sx[2];
	if(r=='A'||r=='B'||r=='C'){
		if(x=='A'||x=='B'||x=='C'){
			if(flag){
				cout<<1;
				flag=1;
			}else{
				cout<<0;
				flag=0;
			}
		}else{
			cout<<0;
			flag=0;
		}
	}
	else if(r=='D'||r=='F'){
		if(x=='F'||x=='D'){
			if(flag){
				cout<<1;
				flag=1;
			}else{
				cout<<0;
				flag=0;
			}
		}else{
			cout<<0;
			flag=0;
		}
	}
	if(flag){
		if((r=='A'&&x=='B')||(r=='B'&&x=='A')){
			cout<<1;
		}else if((r=='B'&&x=='C')||(r=='C'&&x=='B')){
			cout<<1;
		}else if((r=='D'&&x=='F')||(r=='F'&&x=='D')){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	return 0;
} 





