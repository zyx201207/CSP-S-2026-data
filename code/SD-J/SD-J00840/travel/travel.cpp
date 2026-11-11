#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool n=1;
	string c1,c2;
	char s1[2],s2[2];
	cin>>c1;
	for(int i=0;i<=2;i++) cin>>s1[i];
	cin>>c2;
	for(int i=0;i<=2;i++) cin>>s2[i];
	if(c1==c2) {

		cout<<n;
	}
	else {
		n=0;
		cout<<n;	
	}
	char a=s1[0]+s1[1];
	char b=s2[0]+s2[1];
	if(n==1 && a==b) cout<<1;
	else {
		cout<<0;
		n=0;
	}
	
	bool m1=0,m2=0;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') m1=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') m2=1;
	
	if(n==1 && m1==m2) cout<<1;
	else {
		cout<<0;
		n=0;
	}
	
	bool q=1,p=0;
	if(s1[2]=='D'||s1[2]=='C' && s2[2]=='D'||s2[2]=='C') q=0;
	if(s1[2]+1==s2[2] || s1[2]-1==s2[2]) p=1;
	if(n==1 && q==1 && p==1) cout<<1;
	else cout<<0;
	
	

	
	
	
	
	 
	
	
	
	
	return 0;
} 
