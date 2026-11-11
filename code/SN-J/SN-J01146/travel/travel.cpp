#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int q1=0;
	for(int i=0;i<c1.length();i++){
		if(c1[i]!=c2[i]){
			q1=1;
		}
	}
	if(q1==0){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int q2=0;
	for(int i=0;i<s1.length()-1;i++){
		if(s1[i]!=s2[i]){
			q2=1;
		}
	}
	if(q2==0){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	char z1=s1[s1.length()-1];
	char z2=s2[s2.length()-1];
	int q3;
	if((z1=='A'||z1=='B'||z1=='C')&&(z2=='D'||z2=='E')){
		cout<<0<<0;
		return 0;
	}else if((z2=='A'||z2=='B'||z2=='C')&&(z1=='D'||z1=='E')){
		cout<<0<<0;
		return 0;
	}else{
		cout<<1;
		q3=1;
	}
	if((z1-z2==1||z2-z1==1)&&q3==1){
		cout<<1;
	}else{
		cout<<0;
	}
} 
