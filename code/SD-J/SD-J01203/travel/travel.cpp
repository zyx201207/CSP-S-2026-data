#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int sum;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		sum=1;	
	} 
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&sum==1) cout<<1;
	else{
		cout<<0;
		sum=0;	
	} 
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&sum==1||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&sum==1){
		cout<<1;
	}else{
	cout<<0;
	sum=0;	
	} 
	if(sum==1){
		if(s1[2]=='A'&&s2[2]=='B') cout<<1;
		else if(s1[2]=='B'&&s2[2]=='C') cout<<1;
		else if(s1[2]=='B'&&s2[2]=='A') cout<<1;
		else if(s1[2]=='C'&&s2[2]=='B') cout<<1;
		else if(s1[2]=='D'&&s2[2]=='F') cout<<1;
		else if(s1[2]=='F'&&s2[2]=='D') cout<<1;
	}else cout<<0;
	return 0;
} 
