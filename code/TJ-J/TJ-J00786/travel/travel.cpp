#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int as1=0,as2=0,as3=0,as4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		as1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			as2=1;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='c') as3=1;
				if(s1[2]=='A'&&s2[2]=='B') as4=1;
				if(s1[2]=='B'&&s2[2]=='A') as4=1;
				if(s1[2]=='B'&&s2[2]=='C') as4=1;
				if(s2[2]=='B'&&s1[2]=='A') as4=1;
				if(s2[2]=='B'&&s1[2]=='C') as4=1;
			}
			else if(s1[2]=='F'||s1[2]=='D'){
				if(s2[2]=='F'||s2[2]=='D') as3=1;
				if(s1[2]=='F'&&s2[2]=='D') as4=1;
				if(s1[2]=='D'&&s2[2]=='F') as4=1;
			}
		}
	}
	cout<<as1<<as2<<as3<<as4;
	return 0;
}
