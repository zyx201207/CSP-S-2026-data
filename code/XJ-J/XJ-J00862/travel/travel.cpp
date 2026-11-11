#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r"stdin);
	freopen("travel.out","w"stdout);
	string c1,s1,c2,s2;
	int w=0,m=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	cout<<1;
	for(int i=0;i<=1;i++){
		if(s1[i]==s2[i]){
			w++;
		}}
		if(w==2){
			cout<<1;
		if(s1[2]=='A'){
		if(s2[2]=='B'){
			cout<<1<<1;
			m++;
		}
	}
	if(s1[2]=='B'){
		if(s2[2]=='A'){
			cout<<1<<1;
			m++;
		}
	}
	if(s1[2]=='B'){
		if(s2[2]=='C'){
			cout<<1<<1;
			m++;
		}
	}
	if(s1[2]=='C'){
		if(s2[2]=='B'){
			cout<<1<<1;
			m++;
		}
	}
	if(s1[2]=='D'){
		if(s2[2]=='F'){
			cout<<1<<1;
			m++;
		}
	}
	if(s1[2]=='F'){
		if(s2[2]=='D'){
			cout<<1<<1;
			m++;
		}
	}
	if(m==0){
		cout<<0<<0;
	}
		}
		else{
			cout<<0<<0<<0;
		}
	
	}
	else{
		cout<<0<<0<<0<<0;
	}
	
	return 0;
}