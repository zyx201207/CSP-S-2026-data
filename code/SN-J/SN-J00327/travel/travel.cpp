#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1[0]==a2[0] && a1[1]==a2[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(b1[0]==b2[0] && b1[1]==b2[1] && b1[2]==b2[2]){
		cout<<0<<0;
	}
	else{
		if(b1[0]==b2[0] && b1[1]==b2[1]){
			cout<<1;
			if(b1[2]=='C' && b2[2]=='D' || b1[2]=='D' && b2[2]=='C'){
				cout<<0;
			}
			else{
				cout<<1;
			}	
		}
		else{
			cout<<0<<0;
		}
	}
	if(b1[0]==b2[0] && b1[1]==b2[1]){
		if(b1[2]-b2[2]==1 || b2[2]-b1[2]==1){
			if(b1[2]=='C' && b2[2]=='D' || b1[2]=='D' && b2[2]=='C' || b1[2]==b2[2]){
				cout<<0;
			}
			else{
				cout<<1;
			}
		}
		else{
			cout<<0;
		}
	}
	else if(b2[2]==b1[2]){
		if(b1[0]+b1[1]-b2[0]-b2[1]==1 || b2[0]+b2[1]-b1[0]-b1[1]==1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
}
