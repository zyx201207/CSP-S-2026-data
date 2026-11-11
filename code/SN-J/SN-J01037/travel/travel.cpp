#include<bits/stdc++.h>
using namespace std;
string a,b,n,m;
int main(){
	freopen("travel.in" ,"r",stdin);
	freopen("travel.out" ,"w",stdout);
	cin>>a>>n>>b>>m;
	bool f=0;
	if(a==b){
		cout<<'1';
		f=1;
	}else{
		cout<<'0';
		f=0;
	}
	if(f &&n[0]==m[0] && n[1]==m[1]){
		cout<<'1';
		f=1;
	}else{
		cout<<'0';
		f=0;
	}
	if(f==1){
		if (n[2]=='A' || n[2]=='B' || n[2]=='C'){
			if(m[2]=='A' || m[2]=='B' || m[2]=='C'){
				cout<<'1';
				f=1;
			}else{
				cout<<'0';
				f=0;
			}
		}else if(n[2]=='D' || n[2]=='F'){
			if(m[2]=='D' || m[2]=='F' ){
				cout<<'1';
				f=1;
			}else{
				cout<<'0';
				f=0;
			}
		}
	}else{
		cout<<'0';
		f=0;
	}
	if(f==1){
		if(n[2]=='A' || n[2]=='B' || n[2]=='C' ){
			if(abs(n[2]-m[2])==1 ){
				cout<<'1';
				f=1;
			}else{
				cout<<'0';
				f=0;
			}
		}else if(f==1 && n[2]=='D' && m[2]=='F'){
			cout<<'1';
			f=1;
		}else if(f==1 && n[2]=='F' && m[2]=='D'){
			cout<<'1';
			f=1;
		}else{
			cout<<'0';
			f=0;
		}
	}else{
		cout<<'0';
		f=0;
	}
	
	return 0;
}
