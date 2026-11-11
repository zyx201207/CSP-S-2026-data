#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>> a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a2[0]==b2[0] and a2[1]==b2[1] and a1==b1){
		cout<<1;
	}else{
		cout<<0;
	}
	if((a2[2]-b2[2]==1 and a2[2]!='D') or (b2[2]-a2[2]==1 and b2[2]!='D') or (a2[2]=='D' and b2[2]=='F') or (b2[2]=='D' and a2[2]=='F') or (a2[2]=='A' and b2[2]=='C') or (b2[2]=='A' and a2[2]=='C')){
		if(a2[0]==b2[0] and a2[1]==b2[1] and a1==b1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if((a2[2]-b2[2]==1 and a2[2]!='D') or (b2[2]-a2[2]==1 and b2[2]!='D') or (a2[2]=='D' and b2[2]=='F') or (b2[2]=='D' and a2[2]=='F') ){
		if(a2[0]==b2[0] and a2[1]==b2[1] and a1==b1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
} 
