#include<iostream>
#include<string>
using namespace std;
int n,m;
string n1,m1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>n1>>m>>m1;
	if(n==m){
		cout<<1;
		char c,c1;
		for(char h:n1){
			if(h<='9' && h>='0') c+=h; 
		}
		for(char h1:m1){
			if(h1<='9' && h1>='0') c1+=h1; 
		}
		if(c1==c){
			cout<<1;
		}else{
			cout<<0;
		}
		char r,r1;
		for(char a:n1){
			if(a=='F' || a=='D' || a=='C' || a=='B' || a=='A') r+=a; 
		}
		for(char a1:n1){
			if(a1=='F' || a1=='D' || a1=='C' || a1=='B' || a1=='A') r1+=a1; 
		}
		if(r=='A' || r=='B' || r=='C'){
			if(r1!=r && (r1=='A' || r1=='B' || r1=='C')){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(r=='D' || r=='F'){
			if(r1!=r && (r1=='D' || r=='F')){
				cout<<11;
				return 0;
			}
		}
		if(r=='A' && r1=='B') cout<<1;
		else if(r=='B' && r1=='C') cout<<1;
		else cout<<0;
	}else{
	    cout<<0000;	
	}
	return 0;
}
