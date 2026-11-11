#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1;
	string c2;
	int s1;
	string s2;
	cin>>c1>>c2>>s1>>s2;
	char c3=c2[2];
	char s3=s2[2];
	int c=0;
	if(c1==s1){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==s1&&c2[0]==s2[0]&&c2[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==s1&&c2[0]==s2[0]&&c2[1]==s2[1]&&c3-'A'<=2&&s3-'A'<=2){
		cout<<1;
	}else if(c1==s1&&c2[0]==s2[0]&&c2[1]==s2[1]&&c3-'A'>2&&s3-'A'>2){
		cout<<1;
	}else{
		cout<<0;
	}
	double b=c3-s3;
	if(c1==s1&&c2[0]==s2[0]&&c2[1]==s2[1]&&b==1||b==-1){
		if(c3=='C'&&s3=='D'){
			cout<<0;
			c=1;			
		}else if(c3=='D'&&s3=='C'){
			cout<<0;
			c=1;
		}else{
			cout<<1;
		}
	}else{
		cout<<0;
	}
	
	return 0;
} 
