#include <iostream>
#include <cstring>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2,m,n;
	string s1,s2;
	int a=0,b=0,c=0,d=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a==1;
	}
	
	if(s1[1]==s2[1]){
		b==1;
	}
	m=s1[2];
	n=s2[2];
	m=int(m);
	n=int(n);

	if(m=='A'||m=='B'||m=='C'){
		if(m!='D'||n!='F') c==1;
		
	}
	if(m=='D'&&n=='F') c==1;
	if(m=='F'&&n=='D') c==1;
	
	
	if(m=='A'&&n=='B') d==1;
	if(m=='B'){
		if(n=='C'||n=='A') d==1;
	}
	if(m=='C'&&n=='B') d==1;
	if(m=='D'&&n=='F') d==1;
	if(m=='F'&&n=='D') d==1;
	
	
	if(a!=0) cout<<1;
		else cout<<0;
	if(b!=0) cout<<1;
		else cout<<0;
	if(c!=0) cout<<1;
		else cout<<0;
	if(d!=0) cout<<1;
		else cout<<0;
	
	
	return 0;
}
