#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	c1=(s1[0]-'0')*10+(s1[1]-'0');
	c2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1!=c2){
		cout<<"000";
		return 0; 
	}else{
		cout<<1;
	}
	s1=s1[2];
	s2=s2[2];
	if(s1>="A"&&s1<="C"&&s2>="A"&&s2<="C"){
		cout<<1;
	}else if(s1>="D"&&s1<="F"&&s2>="D"&&s2<="F"){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(s1>s2) swap(s1,s2);
	c1=s1[0];
	c2=s2[0];
	if(c1+1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
