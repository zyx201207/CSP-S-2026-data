#include<bits/stdc++.h>
using namespace std;
string a,c,b,d;
int q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int i=int(b[2]);
	int y=int(d[2]);
	
	if(d[2]=='A' && b[2]=='C'){
		q=1;
	}else if(b[2]=='A' && d[2]=='C'){
		q=1;
	}else if(d[2]=='B' && b[2]=='C'){
		q=1;
	}else if(d[2]=='C' && b[2]=='B'){
		q=1;
	}else if(d[2]=='A' && b[2]=='B'){
		q==1;
	}else if(d[2]=='B' && b[2]=='A'){
		q=1;
	}
	else if(d[2]=='D' && b[2]=='F'){
		q=1;
	}else if(d[2]=='F' && b[2]=='D'){
		q=1;
	}else{
		q=0;
	}
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}if(a==c && b[0]==d[0] && b[1]==d[1]){
		cout<<1;
	}else{
		cout<<0;
	}if(a==c && b[0]==d[0] && b[1]==d[1] && q==1){
		cout<<1;
	}else{
		cout<<0;
	}if(a==c &&abs(i-y)==1 && b[0]==d[0] && b[1]==d[1]&& q==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
