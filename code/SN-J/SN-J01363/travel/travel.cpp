#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int a1=-1,b1=-1,c1=-1,d1=-1;
	cin>>a>>b>>c>>d;
	if(a==c){
	a1=1;
	cout<<"1";}
	else{
	cout<<"0";
	a1=0;}
	if(b[1]==d[1]&&b[0]==d[0]&&a1){
	cout<<"1";
	b1=1;}
	else{
	cout<<"0";
	b1=0;}
	if(((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))&&a1&&b1){
	c1=1;
	cout<<'1';}
	else{
	c1=0;
	cout<<'0';}
	if((d[2]-b[2]==1||b[2]-d[2]==1)&&a1&&b1&&c1)
	cout<<'1';
	else
	cout<<'0';
	return 0;
}
