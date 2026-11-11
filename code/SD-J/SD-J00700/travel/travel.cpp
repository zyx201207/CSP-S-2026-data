#include<bits/stdc++.h>
using namespace std;
int cr,cx;
string sr,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx) cout<<"0000";
	else{
		cout<<"1";
		int pr=(sr[0]-'0')*10+(sr[1]-'0'),px=(sx[0]-'0')*10+(sx[1]-'0');
		if(pr!=px) cout<<"000";
		else{
			cout<<"1";
			int wr=sr[2]-'A',wx=sx[2]-'A';
			if((wr<=2&&wx<=2)||(wr>2&&wx>2)){
				cout<<"1";
				if(abs(wr-wx)==1) cout<<"1";
				else cout<<"0";
			}else{
				cout<<"00";
			}
		}
	}
	return 0;
}
