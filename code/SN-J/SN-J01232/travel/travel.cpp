#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int a=0,b=0,c=0,d=0,s13,s23;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		a+=1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	cout<<a;
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		b+=1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	cout<<b;
	s13=s1[2]-'0';
	s23=s2[2]-'0';
	if(s13<=19 && s23<=19){
		c+=1;
		if(abs(s13-s23)==1){
			d+=1;
		}
	}
	if(20<=s13 && 20<=s23){
		c+=1;
		d+=1;
	}
	cout<<c<<d;
	return 0; 
}
