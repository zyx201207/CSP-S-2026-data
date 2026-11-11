#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
ll a1,b1,a2,b2;
char ch1,ch2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.length();i++){
		a1=(a1*10)+int(c1[i]);
	}
	for(int i=0;i<c2.length();i++){
		a2=(a2*10)+int(c2[i]);
	}
	for(int i=0;i<s1.length()-1;i++){
		b1=(b1*10)+int(s1[i]);
	}
	for(int i=0;i<s2.length()-1;i++){
		b2=(b2*10)+int(s2[i]);
	}
	ch1=s1[s1.length()-1];ch2=s2[s2.length()-1];
	if(a1==a2){
		cout<<1;	
	}else{
		cout<<"0000";
		return 0;
	} 
	
	
	if(b1==b2&&a1==a2){
		cout<<1;	
	}else{
		cout<<"000";
		return 0;
	}
	
	
	if(b1==b2&&a1==a2&&(ch1=='A'||ch1=='B'||ch1=='C')&&(ch2=='A'||ch2=='B'||ch2=='C')){
		cout<<1;		
	}else if(b1==b2&&a1==a2&&(ch1=='D'&&ch2=='F')||(ch1=='F'&&ch2=='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((b1==b2&&a1==a2&&(ch1=='A'||ch1=='B'||ch1=='C')&&(ch2=='A'||ch2=='B'||ch2=='C'))&&ch1=='A'&&ch2=='B'||ch1=='B'&&ch2=='A'||ch1=='B'&&ch2=='C'||ch1=='C'&&ch2=='B'){
		cout<<1;
	}else if(b1==b2&&a1==a2&&(ch1=='D'&&ch2=='F')||(ch1=='F'&&ch2=='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	return 0;
}

