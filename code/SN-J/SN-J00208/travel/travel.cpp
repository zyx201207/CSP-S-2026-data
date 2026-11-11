#include<bits/stdc++.h>
using namespace std;
int main() {
	fropen("xxx.in","r",stdin);
	fropen("xxx.out","w",stdout);
	string c1,c2,c3,c4,k="0000";
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) {
		k[0]='1';
	if(c2[0]*10+c2[1]==c4[0]*10+c4[1]) {
		k[1]='1';
		if((c2[2]>='A'&&c2[2]<='C')&&(c4[2]>='A'&&c4[2]<='C')){
			k[2]='1';
			if(c2[2]=='A'&&c4[2]=='B'){
				k[3]='1';
			}
			else if(c2[2]=='B'&&c4[2]=='C'){
				k[3]='1';
			}
		}
		else if(c2[2]=='D'&&c4[2]=='E'){
			k[2]='1';
			k[3]='1';
		}
		else if(c2[2]=='E'&&c4[2]=='D'){
			k[2]='1';
			k[3]='1';
		}
	}
	}
	cout<<string(k);
	return 0;
}
