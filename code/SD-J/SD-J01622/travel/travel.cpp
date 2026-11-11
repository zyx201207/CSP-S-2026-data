#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>c2>>c3>>c4;
	int xu1=c2[0]-'0'+c2[1]-'0';
	int xu2=c4[0]-'0'+c4[1]-'0';
	if(c1==c3){
	cout<<1;
	if(c2[0]==c4[0] && c2[1]==c4[1]){
	cout<<1;
	if( (c2[2]>'C' && c4[2]>'C') || (c2[2]<'D'&&c4[2]<'D') ){
	cout<<1;	
	if(abs(xu1-xu2)==1){
	if(c2[2]==c4[2]) cout<<1;
	else cout<<0;
	 }
	 else if(abs(xu1-xu2)==0){
	if(abs(c2[2]-c4[2])==1) cout<<1;
	else cout<<0;
	 }
	 else cout<<0;
	}
	else cout<<0<<0;	
	}
	 else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0; 
	return 0;
} 
