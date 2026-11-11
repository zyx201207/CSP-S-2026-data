#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	//cout<<s1<<'\n'<<s2<<'\n'<<s3<<'\n'<<s4<<'\n';
	int x=0;
	for(int i=0;i<s1.size();i++){
		x*=10;
		x+=s1[i]-'0';
	}
	int y=0;
	for(int i=0;i<s3.size();i++){
		y*=10;
		y+=s3[i]-'0';
	}
	if(x!=y){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int a=0;
	for(int i=0;i<s2.size()-1;i++){
		a*=10;
		a+=int(s2[i]-'0');
	}
	int b=0;
	for(int i=0;i<s4.size()-1;i++){
		b*=10;
		b+=int(s4[i]-'0');
	}
	if(a!=b){
		//cout<<a<<' '<<b<<'\n';
		cout<<"000";
		return 0;
	}
	cout<<1;
	int n=0,m=0;
	if(s2[2]=='D'||s2[2]=='F'){
		n=1;
	}else{
		n=2;
	}
	if(s4[2]=='D'||s4[2]=='F'){
		m=1;
	}else{
		m=2;
	}
	if(n!=m){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(n==1){
		cout<<1;
		return 0;
	}
	if((s2[2]=='A'&&s4[2]=='C')||(s2[2]=='C'&&s4[2]=='A')){
		cout<<0;
	}else{
		cout<<1;
	}
	return 0;
} 
