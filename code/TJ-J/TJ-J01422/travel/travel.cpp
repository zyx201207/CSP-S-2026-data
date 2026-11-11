#include<bits/stdc++.h>

using namespace std;

string cc1,cs1,cc2,cs2;
int a,b,c,d;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cc1>>cs1>>cc2>>cs2;
	if(cc1==cc2) {
		a=1;
		if(cs1[1]==cs2[1]&&cs1[1]==cs2[1]) {
			b=1;
			if((cs1[2]=='A'||cs1[2]=='B'||cs1[2]=='C')&&(cs2[2]=='A'||cs2[2]=='B'||cs2[2]=='C')||(cs1[2]=='E'||cs1[2]=='F')&&(cs2[2]=='E'||cs2[2]=='F')) {
				c=1;
				if(abs(cs1[2]-cs2[2])==1) d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
