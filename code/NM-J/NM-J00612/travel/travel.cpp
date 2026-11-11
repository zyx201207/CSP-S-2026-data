#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,a=" ",b=" ";
	cin>>c1>>s1>>c2>>s2;
	char x=s1[2],y=s2[2];
//	cout<<x<<y;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
		
	} 
	for(int i=0;i<2;i++){
		a+=s1[i];
	}
	for(int i=0;i<2;i++){
		b+=s2[i];
	}
//	cout<<a<<b;
	if(c1==c2&&a==b){
		cout<<1;		
	}else{
		cout<<0;
	}
	if(c1==c2&&a==b&&((x=='A'&&y=='B')||(x=='A'&&y=='C')||(x=='C'&&y=='B')||(x=='B'&&y=='A')||(x=='C'&&y=='A')||(x=='B'&&y=='C')||(x=='D'&&y=='F')||(x=='F'&&y=='D'))){
		cout<<1;		
	}else{
		cout<<0;
	}
	if(c1==c2&&a==b&&((x=='A'&&y=='B')||(x=='C'&&y=='B')||(x=='B'&&y=='A')||(x=='B'&&y=='C')||(x=='D'&&y=='F')||(x=='F'&&y=='D'))){
		cout<<1;	
	}else{
		cout<<0;
	}
	return 0;
}
