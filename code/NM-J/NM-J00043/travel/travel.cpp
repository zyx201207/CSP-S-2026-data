#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string p,q; //µÚ¼¸ÅÅ 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d;
	p=b[0];
	q=d[0];
	p+=b[1];
	q+=d[1];
	char m=b[2],n=d[2]; //×ùÎ»×ÖÄ¸	
	//cout<<a<<" "<<b<<" "<<c<<" "<<d;
	//cout<<p<<q<<m<<n;
	bool A=0,B=0,C=0,D=0;
	
	if (a==c) A=1;
	if (A && p==q) B=1;
	if (B && ((m>='D' && n>='D') || (m<='C' && n<='C'))) C=1;
	if (C && (m-n==1 || m-n==-1)) D=1;
	cout<<A<<B<<C<<D;
	return 0; 
	
}
