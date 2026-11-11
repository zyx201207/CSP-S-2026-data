#include<bits\stdc++.h>
using namespace std;
int a[101],b[101],c[101],d[101],m,n,k,o;
string s,l;
int main(){
	cin>>a[1]>>a[2];
	cin>>b[1]>>b[2];
	cin>>s;
	cin>>c[1]>>c[2];
	cin>>d[1]>>d[2];
	cin>>l;
	if(a[1]==c[1]&&a[2]==c[2]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(b[1]==d[1]&&b[2]==d[2]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	m=stoi(s);
	n=stoi(l);
	if(a[1]==c[1]&&a[2]==c[2]&&b[1]==d[1]&&b[2]==d[2]&&n<3&&m<3||n>3&&m>3){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	k=m-n;
	k=abs(k);
	if(a[1]==c[1]&&a[2]==c[2]&&b[1]==d[1]&&b[2]==d[2]&&k==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
