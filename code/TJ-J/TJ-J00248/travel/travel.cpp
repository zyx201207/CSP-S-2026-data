#include <bits/stdc++.h>

using namespace std;

#define int long long
string a,a1;
string b,b1;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1;
	cin>>b>>b1;
	if(a==b){
		cout<<1;
	}else{
		cout<<0;
	}
	bool p=true;
	for(int i=0;i<=1;i++){
		if(a1[i]!=b1[i]){
			p=false;
			break;
		}
	}
	if(a1==b1){
		cout<<0<<0<<0;
		return 0;
	}
	if(p==true){
		cout<<1;
		if(a1[2]==b1[2]){
			cout<<0<<0;
			return 0;
		}
		if(a1[2]=='A'){
			if(b1[2]!='B' and b1[2]!='C'){
				cout<<0;
			}else{
				cout<<1;
			}
			if(b1[2]=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(a1[2]=='B'){
			if(b1[2]!='A' and b1[2]!='C'){
				cout<<0;
			}else{
				cout<<1;
			}
			if(b1[2]=='C'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(a1[2]=='C'){
			if(b1[2]!='B' and b1[2]!='A'){
				cout<<0;
			}else{
				cout<<1;
			}
			if(b1[2]=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(a1[2]=='D'){
			if(b1[2]!='E'){
				cout<<0;
			}else{
				cout<<1;
			}
			if(b1[2]=='E'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(a1[2]=='E'){
			if(b1[2]!='D'){
				cout<<0;
			}else{
				cout<<1;
			}
			if(b1[2]=='D'){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0<<0<<0;
	}
	return 0;
} 
