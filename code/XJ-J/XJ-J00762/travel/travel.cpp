#include<bits/stdc++.h>
using namespace std;
string cR,sR,cX,sX;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cR>>sR>>cX>>sX;
	if(cR==cX){
		cout<<1;
		if(sR[0]==sX[0]&&sR[1]==sX[1]){
			cout<<1;
			if(sR[2]<='C'&&sX[2]<='C'){
				cout<<1;
				if(sR[2]=='A'&&sX[2]=='B'){
					cout<<1;
				}else if(sR[2]=='B'&&sX[2]=='C'){
					cout<<1;
				}else if(sR[2]=='B'&&sX[2]=='A'){
					cout<<1;
				}else if(sR[2]=='C'&&sX[2]=='B'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(sR[2]>='D'&&sX[2]>='D'){
				cout<<"11";
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
