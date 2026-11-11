#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	char s1[101]={};
	char s2[101]={};
	int a=0,b=0,x=0,y=0;
	cin>>c1>>s1>>c2>>s2;
	int o=1,j=0;
	while(o>0){
		if(c1<c2||c1>c2){
			a=0,b=0,x=0,y=0;
			j=0;
			break;
		}
		else{
			a=1;
			for(int i=0;i<=1;i++){
				if(s1[i]!=s2[i])  j=1;
			}
			if(j==1) break;
			if(j==0) b=1;
			if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C') x=1;
			if(s1[2]=='B'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='A') x=1;
			if(s1[2]=='C'&&s2[2]=='B'||s1[2]=='C'&&s2[2]=='A') x=1;
			if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D') x=1;
			if(x==0) break;
			if(abs(int(s1[2])-int(s2[2]))==1) y=1;
		}
		o--;	
	}
	cout<<a<<b<<x<<y;
	return 0;
}
