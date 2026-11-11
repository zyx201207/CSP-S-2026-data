#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f=1;
	for(int i=0;i<=c1.size();i++){
		if(c1[i]!=c2[i]){
			f=0;
			break;
		}
	}
	if(f==0){
		cout<<0;
	}else{
		cout<<1;
	}
	bool f1=1;
	for(int i=0;i<c1.size();i++){
		if(s1[i]!=s2[i]){
			f1=0;
			break;
		}
	}
	if(f1==0){
		cout<<0;
	}else if(f==0&&f1==1){
		cout<<0;
	}else{
		cout<<1;
	}
	char q1=s1[s1.size()-1],q2=s2[s2.size()-1];
	if((q1=='A'&&q2=='B')||(q1=='A'&&q2=='C')||(q1=='B'&&q2=='C')||(q1=='B'&&q2=='A')||(q1=='C'&&q2=='A')||(q1=='C'&&q2=='B')||(q1=='D'&&q2=='F')||(q1=='F'&&q2=='D')){
		if(f1==1&&f==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
			cout<<0;
	}
	if((q1=='A'&&q2=='B')||(q1=='B'&&q2=='A')||(q1=='B'&&q2=='C')||(q1=='C'&&q2=='B')||(q1=='D'&&q2=='F')||(q1=='F'&&q2=='D')){
		if(f1==1&&f==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
			cout<<0;
	}
	return 0;
} 
