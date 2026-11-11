#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2,a=0,b=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<1;
		if(s1[-1]==s2[-1]){
			cout<<1;
			if((s1[0]=='A'||s1[0]=='B')&&(s2[0]=='A'||s2[0]=='B')){
				cout<<1;
				a=1;
				if((s1[0]=='A')&&(s2[0]=='B')){
					cout<<1;
					b=1;
			 	}
			 	if((s2[0]=='A')&&(s1[0]=='B')){
					cout<<1;
					b=1;
			 	}
			}
			if(a==0){
			
				if((s1[0]=='A'||s1[0]=='C')&&(s2[0]=='A'||s2[0]=='C')){
					cout<<1;
					a=1;
					if(b==0){
						if((s1[0]=='A')&&(s2[0]=='C')){
							cout<<1;
							b=1;
			 			}
			 			if((s2[0]=='A')&&(s1[0]=='C')){
							cout<<1;
							b=1;
			 			}
					}
				}
			
			
			}
			if(a==0){
			
				if((s1[0]=='B'||s1[0]=='C')&&(s2[0]=='B'||s2[0]=='C')){
					cout<<1;
					a=0;
					if(b==0){
						if((s1[0]=='B')&&(s2[0]=='C')){
							cout<<1;
							b=1;
			 			}
			 			if((s2[0]=='B')&&(s1[0]=='C')){
							cout<<1;
							b=1;
			 			}
					}
				}
				
			}
			
			if(a==0){
				if((s1[0]=='D'||s1[0]=='F')&&(s2[0]=='D'||s2[0]=='F')){
					cout<<1;
					a=1;
					if(b==0){
						if((s1[0]=='D')&&(s2[0]=='F')){
							cout<<1;
							b=1;
			 			}
			 			if((s2[0]=='D')&&(s1[0]=='F')){
							cout<<1;
							b=1;
			 			}
			 			if(b==0){
			 				cout<<0;
						 }
					}
				}
			}
			if(a==0){
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0;
	}
	freopen("trave.in","r",stdin);
	freopen("trave.out","w",stdout);
	return 0;
} 
