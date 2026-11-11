#include<bits/stdc++.h>
using namespace std;

int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//02 01A 02 01B||s1[2]==b&&s2[2]==b
	string c1, s1, c2, s2;
	string a="ABC";
	string b="DF";
	
	cin>>c1>>s1>>c2>>s2; 
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1[2]==a[0]||s1[2]==a[1]||s1[2]==a[2]&&s2[2]==b[0]||s2[2]==b[1]){
		cout<<0;}
	else{
		cout<<1;}
	if(s1[2]==a[0]&&s2[2]==a[1]||s1[2]==a[1]&&s2[2]==a[2]||s1[2]==b[0]&&s2[2]==b[1]){
		cout<<1;}
	else{
		cout<<0;}
	
	//out<<a+b+c+d<<endl;
	return 0;
}
