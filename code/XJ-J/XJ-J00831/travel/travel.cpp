#include<bits/stdc++.h>
using namespace std;

int main(){
	string c1,c2,c3,c4;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(c1==c3) cout<<1;
	else cout<<0;
	if(c2[1]==c4[1]){
		if(c2[2]==c4[2]) cout<<1;
		else cout<<0;	
	}
	else cout<<0;
	if(c2[3]=='A'||c2[3]=='B'||c2[3]=='C'&&c4[3]=='A'||c4[3]=='B'||c4[3]=='C'){
		cout<<1;
		if(c2[3]=='A'){
			if(c4[3]=='B') cout<<1;
			else cout<<0;
		}
		else if(c2[3]=='B'){
			cout<<1;
		}
		else{
			if(c4[3]=='B') cout<<1;
			else cout<<0;
		}
	}
	else if(c2[3]=='D'||c2[3]=='E'&&c4[3]=='D'||c4[3]=='E'){
		cout<<1<<1;
	}
	else cout<<0<<0;
	
	return 0;
}