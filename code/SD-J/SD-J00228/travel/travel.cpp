#include<bits/stdc++.h>
#define int long long
using namespace std;
string cr,sr,cx,sx;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<"1";
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			cout<<"1";
			if(('A'<=sr[2]&&'C'>=sr[2]&&'A'<=sx[2]&&'C'>=sx[2])||(('D'==sr[2]||'F'==sr[2])&&('D'==sx[2]||'F'==sx[2]))){
				cout<<"1";
				if(sr[2]>sx[2]) swap(sr[2],sx[2]);
				if((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='C')||(sr[2]=='D'&&sx[2]=='F')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
