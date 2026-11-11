#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c11,s11,c22,s22;
	cin>>c11>>s11>>c22>>s22;
	if(c11==c22){
		if(s11[1]==s22[1] && s11[0]==s22[0]){
			if(s11[2]=='A'){
				if(s22[2]=='B') cout<<"1111";
				else if(s22[2]=='D' || s22[2]=='E') cout<<"1100";
				else cout<<"1110";
			}else if(s11[2]=='B'){
				if(s22[2]=='A' || s22[2]=='C') cout<<"1111";
				else cout<<"1100";
			}else if(s11[2]=='C'){
				if(s22[2]=='B') cout<<"1111";
				else if(s22[2]=='D' || s22[2]=='E') cout<<"1100";
				else cout<<"1110";
			}else if(s11[2]=='D'){
				if(s22[2]=='E') cout<<"1111";
				else cout<<"1100";
			}else{
				if(s22[2]=='D') cout<<"1111";
				else cout<<"1100";
			}
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
