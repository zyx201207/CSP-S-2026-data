#include<bits/stdc++.h>
using namespace std;
string sr,cr,sx,cx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	int ok=0;
	if(cx!=cr){
		cout<<0<<0<<0<<0;
		return 0;
	}//不在同一个车厢 
	else cout<<1;//在同一个车厢 
    if(sr[0]==sx[0]&&sr[1]==sx[1])cout<<1;//在同一排 
    else{
		cout<<0<<0<<0;
		return 0;
	}//不在同一排 
    if((sx[2]=='A'||sx[2]=='B'||sx[2]=='C')&&(sr[2]=='A'||sr[2]=='B'||sr[2]=='C'))cout<<1;
    else if((sr[2]=='D'&&sx[2]=='F')||(sx[2]=='D'&&sr[2]=='F')){
    	cout<<11;
    	return 0;
	}
    //在同侧 
    else{
		cout<<0<<0;
		return 0;
	}//不在同侧
	if((sr[2]=='A'||sr[2]=='C')&&sx[2]=='B'){
		cout<<1;
	}
	else if((sx[2]=='A'||sx[2]=='C')&&sr[2]=='B'){
		cout<<1;
	}
	else if((sr[2]=='D'&&sx[2]=='F')||(sx[2]=='D'&&sr[2]=='F')){
		if(sr[2]=='F'&&sx[2]=='D'){
			cout<<1;
		}
		if(sx[2]=='F'&&sr[2]=='D'){
			cout<<1;
		}
	}
	else cout<<0;
	return 0;
}
