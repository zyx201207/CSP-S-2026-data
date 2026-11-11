#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int a[15],b[15],c[15],d[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		a[i]=c1[i]-'0';
	}
	for(int i=0;i<=1;i++){
		b[i]=c2[i]-'0';
		if(a[i]!=b[i]){
			cout<<"0000";
			return 0;
		}
	}
	for(int i=0;i<=1;i++){
		c[i]=s1[i]-'0';
	}
	for(int i=0;i<=1;i++){
		d[i]=s2[i]-'0';
		if(d[i]!=c[i]){
			cout<<"1000";
			return 0;
		}
	}
	if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F'))||((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F'))){
		cout<<"1100";
	}
	else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		cout<<"1111";
	}
	else{
		cout<<"1110";
	}
	return 0;
}