#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr[0]==cx[0]&&cr[1]==cx[1]){
		a=1;
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			b=1;
			if(sr[2]=='A'){
				if(sx[2]=='B'){
					c=1,d=1;
				}else if(sx[2]=='C'){
					c=1,d=0;
				}
			}else if(sr[2]=='B'){
				if(sx[2]=='A'){
					c=1,d=1;
				}else if(sx[2]=='C'){
					c=1,d=1;
				}
			}else if(sr[2]=='C'){
				if(sx[2]=='A'){
					c=1,d=0;
				}else if(sx[2]=='B'){
					c=1,d=1;
				}
			}else if(sr[2]=='D'){
				if(sx[2]=='E'){
					c=1,d=1;
				}
			}else if(sr[2]=='E'){
				if(sx[2]=='D'){
					c=1,d=1;
				}
			}
		}
	}else{
		a=0,b=0,c=0,d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
