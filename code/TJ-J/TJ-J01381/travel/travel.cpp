#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool b=0,b1=0,b2=0,b3=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		b=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			b1=1;
			if(s1[2]<='C'&&s2[2]<='C'){
				b2=1;
				if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='A'&&s1[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s2[2]=='B'&&s1[2]=='C')) b3=1;
			}
			if(s1[2]>='D'&&s2[2]>='D'){
				b2=1;
				if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')) b3=1;
			}
		}
	}
	cout<<b<<b1<<b2<<b3;
	return 0;
}

