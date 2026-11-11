#include<bits/stdc++.h>
using namespace std;
string a1,b1,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((a1[0]==b1[0]||a1[1]==b1[1])&&a==b){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(((a1[2]<'D'&&b1[2]<'D')||(a1[2]>'C'&&b1[2]>'C'))&&((a1[0]==b1[0]||a1[1]==b1[1])&&a==b)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((char(a1[2]-1)==b1[2]||char(a1[2]+1)==b1[2])&&(((a1[2]<'D'&&b1[2]<'D')||(a1[2]>'C'&&b1[2]>'C'))&&((a1[0]==b1[0]||a1[1]==b1[1])&&a==b))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}