#include<bits/stdc++.h>
using namespace std;
string ra,rb,xa,xb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>ra>>rb>>xa>>xb;
	if(ra!=xa)cout<<"0000";
	else {
		if(rb[0]!=xb[0]||rb[1]!=xb[1])cout<<"1000";
		else {
			if(rb[2]<='C'&&xb[2]<='C'){
				if(abs(rb[2]-xb[2])==1)cout<<"1111";
				else cout<<"1110";
			}
			else if(rb[2]>'C'&&xb[2]>'C')cout<<"1111";
			else cout<<"1100";	
		}
	}
}