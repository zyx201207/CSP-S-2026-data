#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(sr.substr(0,2)==sx.substr(0,2)){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(sr[2]<='C'){
		if(sx[2]<='C'){
			cout<<1;
			if(sx[2]==sr[2]+1||sr[2]==sx[2]+1){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	else{
		if(sx[2]>='D'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	return 0;
}
