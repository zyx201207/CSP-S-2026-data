#include<bits/stdc++.h>
using namespace std;

int cx1,cx2;
string s1,s2;
int num1,num2;
char alph1,alph2;
bool tf1,tf2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>s1>>cx2>>s2;
	num1=(s1[0]-'0')*10+(s1[1]-'0');
	num2=(s2[0]-'0')*10+(s2[1]-'0');
	alph1=s1[2];
	alph2=s2[2];
	if(alph1>='A' && alph1<='C'){
		tf1=true;
	}
	if(alph2>='A' && alph2<='C'){
		tf2=true;
	}
	
	
	if(cx1==cx2){
		cout<<1; 
		if(num1==num2){
			cout<<1;
			if(tf1==tf2){
				cout<<1;
				if(abs(alph1-alph2)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	
	return 0;
} 
