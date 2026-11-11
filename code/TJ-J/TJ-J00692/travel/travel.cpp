#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	int c1,c2,n=0;	char s1[3],s2[3];
	cin>>c1>>s1>>c2>>s2;
	int s11=(s1[0]-'0')*10+s1[1]-'0';
	int s22=(s2[0]-'0')*10+s2[1]-'0'; 
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		n=1;
	}
	if(s11==s22&&n==0){
		cout<<1;
	}else{
		cout<<0;
		n=1;
	}
	if(s1[2]>'C'&&s2[2]>'C'&&n==0){
		cout<<1; 
	}else{
		if(s1[2]<='C'&&s2[2]<='C'&&n==0){
			cout<<1;
		}else{
			cout<<0;
			n=1;
		}
	}
	if(s1[2]<='C'&&s2[2]<='C'&&n==0){
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
		cout<<1;
		return 0;
	}else{
		cout<<0;
		return 0;
	}
	}else{
		if(s1[2]=='D'&&s2[2]=='F'){
			cout<<1;
		}else{
			if(s1[2]=='F'&&s2[2]=='D'){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}
	return 0;
}
