#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen<"travel.in","r",stdin>; 
	freopen<"travel.out","w",stdout>;
	string c1,c2,s1,s2;
	int q1=0,q2=1,q3=0,q4=0;
	cin >>c1>>s1>>c2>>s2;
	if (c1==c2) q1=1;
	char i=1;
	if (s1+i==s2) q4=1;
	if (s2+i==s1) q4=1;
	cout<<q1<<q2<<q3<<q4;
	return 0;
} 
