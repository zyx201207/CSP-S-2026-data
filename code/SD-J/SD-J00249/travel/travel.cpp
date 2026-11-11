#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string cq,sq,cw,sw;
	cin>>cq>>sq>>cw>>sw;
	if(cq==cw){
		cout<<1;
		if(sq[0]==sw[0]&&sq[1]==sw[1]){
			cout<<1;
			if((sq[2]=='A'&&sw[2]=='B')||(sq[2]=='A'&&sw[2]=='C')||(sq[2]=='B'&&sw[2]=='C')||(sq[2]=='D'&&sw[2]=='F')||(sq[2]=='B'&&sw[2]=='A')||(sq[2]=='C'&&sw[2]=='A')||(sq[2]=='C'&&sw[2]=='B')||(sq[2]=='F'&&sw[2]=='D')){
				cout<<1;
				if((sq[2]=='A'&&sw[2]=='C')||(sq[2]=='C'&&sw[2]=='A'))
					cout<<0;
				else cout<<1;
			}
			else cout<<"00";
		} 
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
