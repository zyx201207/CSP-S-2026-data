#include<bits/stdc++.h>
using namespace std;
string cr,cx,sx,sr;
int f=1,f2=0,f3=0,f4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	for(int i=0;i<=1;i++){
		if(cr[i]!=cx[i]) f=0;
	}
	if(sr[0]==sx[0]&&sr[1]==sx[1]) f2=1;
	if(f2){
		if(sr[2]=='A'||sr[2]=='B'||sx[2]=='C'){
			if(sx[2]=='A'||sx[2]=='B'||sx[2]=='C') f3=1;
		}else{
			if(sx[2]=='D'||sx[2]=='F') f3=1;
		}
	}
	if(f3){
		if(sx[2]=='A'){
			if(sr[2]=='B') f4=1;
		}
		if(sx[2]=='B'){
			if(sr[2]=='A'||sr[2]=='C') f4=1;
		}
		if(sx[2]=='C'){
			if(sr[2]=='B') f4=1;
		}
		if(sx[2]=='D'){
			if(sr[2]=='F') f4=1;
		}
		if(sx[2]=='F'){
			if(sr[2]=='D') f4=1;
		}
	}
	if(f==0){
		f2=0,f3=0,f4=0;
	}
	if(f2==0){
		f3=0,f4=0;
	}
	if(f3==0){
		f4=0;
	}
	cout<<f<<f2<<f3<<f4;
	return 0;
}
