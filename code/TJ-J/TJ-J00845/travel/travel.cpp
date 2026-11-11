#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int f2=1;
	if(c1==c2)cout<<1;
	else{
		cout<<0;
		f2=0;
	} 
	string s3=s1;
	string s4=s2;
	int f=1;
	int f1=1;
	for(int i=0;i<2;i++){
		if(s3[i]!=s4[i]){
			f=0;
			f1=0;
			break;
		}
	}
	if(f&&f2){
		cout<<1;
		f1=1;
	}
	else cout<<0;
	if(f2&&f1&&(s3[2]=='A'||s3[2]=='B'||s3[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')||(s3[2]=='D'||s3[2]=='E')&&(s4[2]=='D'||s4[2]=='E'))cout<<1;
	else cout<<0;
	if(s3[2]+1==s4[2]||s4[2]+1==s3[2]){
		if(!(s3[2]=='C'&&s4[2]=='D'||s3[2]=='D'&&s4[2]=='C')){
			if(f1&&f2)cout<<1;
			else cout<<0;
		}
		else cout<<0; 
	}
	else cout<<0;
	return 0;
} 
