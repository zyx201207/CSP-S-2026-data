#include <bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
string ans="0000";

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		ans[0]='1';
		if(sr[0]==sx[0] && sr[1]==sx[1]){
			ans[1]='1';
			char a=sr[2],b=sx[2];
			if((a=='A' && b=='B') || (a=='A' && b=='C') || (a=='B' && b=='A') || (a=='B' && b=='C') || (a=='C' && b=='A') || (a=='C' && b=='B') || (a=='D' && b=='F') || (a=='E' && b=='F')){
				ans[2]='1';
				if((a=='A' && b=='B') || (a=='B' && b=='A') || (a=='B' && b=='C') || (a=='C' && b=='B') || (a=='D' && b=='F') || (a=='F' && b=='D')){
					ans[3]='1';				
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
