#include<bits/stdc++.h>
using namespace std;
string s1,s2,p1,p2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout);
	cin>>s1>>s2>>p1>>p2;
	if(s1==p1){
		a=1;
		if(s2[0]==p2[0]&&s2[1]==p2[1]){
			b=1;
			if((s2[2]+p2[2]=='A'+'B')||(s2[2]=='C'&&p2[2]=='B')||(p2[2]=='C'&&s2[2]=='B')||(s2[2]+p2[2]=='A'+'C')||(s2[2]+p2[2]=='D'+'F')){
				c=1;
				if(!(s2[2]+p2[2]=='A'+'C'))d=1;
			}
		}
	}cout<<a<<b<<c<<d;
	return 0;
}
