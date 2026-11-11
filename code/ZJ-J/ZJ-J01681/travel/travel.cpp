#include<bits/stdc++.h>
using namespace std;
struct node{
	string c;
	string z;
}r,x;
int main(){
	cin>>r.c>>r.z;
	cin>>x.c>>x.z;
	if(r.c==x.c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(int(r.z[0]-'0'*10)+int(r.z[1]-'0')==int(x.z[0]-'0'*10)+int(x.z[1]-'0')){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(r.z[2]>'C'&&x.z[2]>'C'||r.z[2]<='C'&&x.z[2]<='C'){
		cout<<1;
	}
	else{
		cout<<"00";
	}
	if(r.z[2]>'C'){
		cout<<1; 
	}
	else if(abs(int(r.z[2]-x.z[2]))==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
}