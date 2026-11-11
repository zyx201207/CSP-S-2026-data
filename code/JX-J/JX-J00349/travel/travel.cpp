#include<bits/stdc++.h>
using namespace std;
string Rc,Rp,Xc,Xp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>Rc>>Rp>>Xc>>Xp;
	string Rrow,Xrow; int Rcol,Xcol;
	Rrow=Rp[0]+Rp[1],Rcol=Rp[2]-'A';
	Xrow=Xp[0]+Xp[1],Xcol=Xp[2]-'A';
	if(Rc==Xc){
		cout<<1;
		if(Rrow==Xrow){
			cout<<1;
			if((Rcol<=3&&Xcol<=3)||(Rcol>3&&Xcol>3)){
				cout<<1;
				if(Rcol-Xcol==1||Rcol-Xcol==-1){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
