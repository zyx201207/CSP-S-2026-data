#include <bits/stdc++.h>
using namespace std;
int cr,cx;
string s="0000",xa,xb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>xa>>cx>>xb;
	if(cr==cx){
		s[0]='1';
		if(xa[0]==xb[0]&&xa[1]==xb[1]){
			s[1]='1';
			if((xa[2]=='A'||xa[2]=='B'||xa[2]=='C')&&(xb[2]=='A'||xb[2]=='B'||xb[2]=='C')&&xa[2]!=xb[2]){
				s[2]='1';
				if(xa[2]+1==xb[2]||xa[2]-1==xb[2]){
					s[3]='1';
				}
			}else if((xa[2]=='F'||xa[2]=='D')&&(xb[2]=='F'||xb[2]=='D')&&xa[2]!=xb[2]){
				s[2]='1';
				if(xa[2]+1==xb[2]||xa[2]-1==xb[2]){
					s[3]='1';
				}
			}

		}
	}
	cout<<s;
	return 0;
}
