#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio();
	cin.tie();
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string Rc,Rs,Xc,Xs;
	cin>>Rc>>Rs>>Xc>>Xs;
	int Rp=Rs[0]*10+Rs[1];
	int Xp=Xs[0]*10+Xs[1];
	char Rw=Rs[2],Xw=Xs[2];
	if(Rc==Xc){
		cout<<1;
		if(Rp==Xp){
			cout<<1;
			if( (Rw>='A'&&Rw<='C'&&Xw>='A'&&Xw<='C')
				|| (Rw>='D'&&Rw<='F'&&Xw>='D'&&Xw<='F') ){
				cout<<1;
				if(abs(Rw-Xw)==1&&(!( (Rw=='C'&&Xw=='D') || (Rw=='D'&&Xw=='C') ))){
					cout<<1; 
				}else{
					cout<<0;
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

