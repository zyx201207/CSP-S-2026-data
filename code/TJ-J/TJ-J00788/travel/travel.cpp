#include <bits/stdc++.h>
using namespace std;
int q,w,e,r;
char a,b,c,d,n,m;
string c1,s1,c2,s2;
int main(){
cin>>c1>>s1>>c2>>s2;
a=s1[0];
b=s1[1];
c=s2[0];
d=s2[1];
n=s1[2];
m=s2[2];
if(c1==c2){
	q=1;
	if(a==c&&b==d){
		w=1;
		if(((n=='A' || n=='B' || n=='C')&&(m=='A' || m=='B' || m=='C')) || ((n=='D' || n=='F')&&(m=='D' || m=='F'))){
			e=1;
			if(n==m-1 || n==m+1)r=1;
		}
	}
	
}cout<<q<<w<<e<<r;
	return 0;
}
