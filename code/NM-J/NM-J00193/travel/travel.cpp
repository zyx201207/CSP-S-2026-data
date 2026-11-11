#include<bits/stdc++.h>
using namespace std;
int r,x;
string sr,sx;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>sr>>x>>sx;
	if(r==x){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(sr[0]==sx[0]&&sr[1]==sx[1]){
		cout<<"1";
	}else{
		cout<<"000";
	}
	if(sx[2]!='D'&&sx[2]!='F'&&sr[2]!='D'&&sr[2]!='F'){
		cout<<"1";
	}else if(sx[2]=='D'&&sr[2]=='F'&&sr[2]=='D'&&sx[2]=='F'){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(sr[2]+1==sx[2]||sx[2]+1==sr[2]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
