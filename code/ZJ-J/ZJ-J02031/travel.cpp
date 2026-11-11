#include<bits/stdc++.h>
using namespace std;
int c1,c2,sp1,sp2;
char sz1,sz2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c1>>sp1>>sz1>>c2>>sp2>>sz2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(sp1==sp2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(((sz1=='A'||sz1=='B'||sz1=='C')&&(sz2=='A'||sz2=='B'||sz2=='C'))||(sz1=='D'||sz1=='F')&&(sz2=='D'||sz2=='F')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(!((sz1=='C'&&sz2=='D')||(sz1=='D'&&sz2=='F'))&&abs(sz1-sz2)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	
	return 0;
}
