#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	char s1[5],s2[5];
	cin>>c1>>s1>>c2>>s2;
	int r=0,c=0,d=0,e=0;
	if(c1==c2){	cout<<"1";r=1;}	else{cout<<"0";	}
	int a[10]={},b[10]={};
	a[0]=s1[0]-'0';b[0]=s2[0]-'0'; 
	a[1]=s1[1]-'0';b[1]=s2[1]-'0';
	if((a[1]==b[1])&&(a[0]==b[0])){	c=1;}
	if(r==1&&c==1){cout<<"1";}
	else{	cout<<"0";	}
	a[2]=s1[2]-'A';b[2]=s2[2]-'A'; 
	if((a[2]<=2&&b[2]<=2)||(2<a[2]<=4&&2<b[2]<=4)){	d=1;}
	if(r==1&&c==1&&d==1){	cout<<"1";}
	else{	cout<<"0";}
	if(d==1&&(max(a[2],b[2])-1==min(a[2],b[2]))){	e=1;}
	if(r==1&&c==1&&d==1&e==1){	cout<<"1";		}
	else{	cout<<"0";}
	return 0;
}
