#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	n=b[2];
	b[2]=' ';
	m=d[2];
	d[2]=' ';
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			 if(n>='D'&&m>='D'){
				 cout<<"11";
			 }else if(n<'D'&&m<'D'){
				 cout<<1;
				 if(n=='B'||m=='B'){
					 cout<<1;
				 }else{
					 cout<<0;
				 }
			 }else {
				 cout<<"00";
			 }				 
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
