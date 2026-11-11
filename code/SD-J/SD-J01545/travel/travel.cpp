#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	char a,b,c,d; 
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1==c2) a='1';
	else {
		a='0';
	}
for(int i=1;i<=s1.size()-1;i++){
	for(int j=1;j<=s2.size()-1;j++){
	 	if(s1[i]==s2[j])
			b='1';		
		else{
			b='0';
			c='0';
			d='0';
			}		
		}
	if((s1[3]=='A'||s1[3]=='B'||s1[3]=='C'&&s2[3]=='A'||s2[3]=='B'||s2[3]=='C')||(s1[3]=='D'||s1[3]=='F'&&s2[3]=='F'||s2[3]=='D'))
		c='1';	
	else{
		c='0';
		d='0';
		}
		if((s1[3]=='A'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='A'||s1[3]=='A'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='A'||s1[3]=='C'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='C')||(s1[3]=='D'&&s2[3]=='F'||s1[3]=='F'&&s2[3]=='D'))
			d='1';
		else
			d='0';  
}
	cout<<a<<b<<c<<d;	
	return 0;
} 
