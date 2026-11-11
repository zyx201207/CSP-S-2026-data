#include <bits/stdc++.h>
using namespace std;
int a=0,b=0,c=0,d=0,k=0;
string s1,s2,c1,c2;
char x1[8],x2[8],z1[8],z2[8],w1,w2,g1,g2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++){
		x1[i]=c1[i];
	}
	for(int i=0;i<s1.size();i++){
		z1[i]=s1[i];
		g1=z1[2];
		if(z1[2]>='D') w1=1;
		else w1=2;
	}
	for(int i=0;i<c2.size();i++){
		x2[i]=c2[i];
	}
	for(int i=0;i<s2.size();i++){
		z2[i]=s2[i];
		g2=z2[2];
		if(z2[2]>='D') w2=1;
		else w2=2;
	}
	if(abs(g1-g2)==1)  k=1;
	if(x1[0]==x2[0] && x1[1]==x2[1]) a=1;
	if(a==1 && z1[0]==z2[0] &&z1[1]==z2[1]) b=1;
	if(b==1 && w1==w2) c=1;
	if(c==1 && k==1) d=1;
	cout<<a<<b<<c<<d;
	return 0;
}
