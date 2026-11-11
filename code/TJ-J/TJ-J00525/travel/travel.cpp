#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,s3,s4;
bool a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i=0;i<2;i++){
		s3=s1[i];
		s4=s2[i];
		if(s3==s4){
			a=1;
		}else{
			a=0;
		}
	}
	if(a){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		cout<<1;
	}else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(s1[2]=='C'){
		if(s2[2]=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(s1[2]=='D'){
		if(s2[2]=='F'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(s1[2]=='F'){
		if(s2[2]=='D'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

