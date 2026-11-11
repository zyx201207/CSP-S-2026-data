#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool flag=true;
int x,y,a,b;
int c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s2[0]=='0')  x=s2[1]-'0';
	else  x=10+(s2[1]-'0');
	if(s4[0]=='0')  y=s4[1]-'0';
	else  y=10+(s4[1]-'0');
	if(s2[2]>='A'&&s2[2]<='C')  a=1;
	else  a=0;
	if(s4[2]>='A'&&s4[2]<='C')  b=1;
	else  b=0;
	c=s2[2];
	d=s4[2];
	
	if(s1==s3)  cout<<1;
	else{
		cout<<0;
		flag=false;
	}
	
	if(flag&&x==y)  cout<<1;
	else{
		cout<<0;
		flag=false;
	}
	
	if(flag&&a==b)  cout<<1;
	else{
		cout<<0;
		flag=false;
	}
	
	if(flag){
		if(a==1&&b==1){
			if(abs(c-d)==1)  cout<<1;
			else  cout<<0;
		}
	}
	else  cout<<0;
	return 0;
} 
