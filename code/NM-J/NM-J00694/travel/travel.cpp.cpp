#include<bits/stdc++.h> 
using namespace std;
int main(){
	//preopen("travel.in","r",stdin);
	//preopen("travel.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		cin>>s[i];
	}
	int s3=s[0];
	int s4=s[2];
	if(s3==s4){
		cout<<1;
	}
	else{
		cout<<0;
	}
	int s1=s[1];
	int s2=s[3];
	int a=s1/100;
	int b=s2/100;
	if(a==b){
		cout<<1;
	} 
	else{
		cout<<0;
	}
	int c=s1%100;
	int d=s2%100;
	if(c==65){
		if(d==66||c==67){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
	}
	else if(c==66){
		if(d==65||c==67){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
	}
	else if(c==67){
		if(d==65||c==66){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
	}
	else if(c==68){
		if(d==69){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
	}
	else if(c==69){
		if(d==68){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	int e=c;
	int f=d;
	if(e==65){
		if(f==66){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
	}
	else if(e==66){
		if(f==67||f==65){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
	}
	else if(e==67){
		if(f==66){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
	}
	else if(e==68){
		if(f==69){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
	}
	else if(e==69){
		if(f==68){
			cout<<1;
			
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
	}
