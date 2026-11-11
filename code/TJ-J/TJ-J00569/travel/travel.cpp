#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int flag=1,oen=0;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0] and a[1]==c[1]) {
		cout<<1;
		oen=1;
	}
	else {
		cout<<0;
		oen=0;
	}
	
	if((b[1]==d[1] and b[0]==d[0]) and oen){
		cout<<1;
	}
	else {
		cout<<0;
		oen=0;
	} 
	
	if(((b[2]=='A' or b[2]=='B' or b[2]=='C') and (d[2]=='A' or d[2]=='B' or d[2]=='C') or (b[2]=='D' or b[2]=='F') and (d[2]=='D' or d[2]=='E')) and oen){
		cout<<1;
	}
	else {
		cout<<0;
		oen=0;
	}
	if((b[2]=='D' or b[2]=='C') and (d[2]=='D' or d[2]=='C')){
		flag=0;;
	}
	if((char(b[2])-char(d[2])==1 or char(b[2])-char(d[2])==-1) and flag and oen){
		cout<<1;
	}
	else cout<<0;
} 
