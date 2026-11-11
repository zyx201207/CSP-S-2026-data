#include<bits/stdc++.h>
using namespace std;
string cr,cx,sr,sx;
int px,pr,wx,wr;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr[0]==cx[0]&&cx[1]==cr[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(sr[0]==sx[0]&&sx[1]==sr[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	pr=(sr[2]-'A')+1;
	px=(sx[2]-'A')+1;
	if(pr==6){
		pr=5;
	}
	if(px==6){
		px=5;
	}
	if(pr<=3){
		wr=1;
	}
	else{
		wr=2;
	}
	if(px<=3){
		wx=1;
	}
	else{
		wx=2;
	}
	
	if(wx==wr){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(abs(px-pr)==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
