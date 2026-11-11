#include<bits/stdc++.h>
using namespace std;
int rx,xx,rz,xz;
string cr,cx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rx>>cr>>xx>>cx;
//	cout<<rx<<' '<<cr<<' '<<xx<<' '<<cx;
	if(rx==xx){
		cout<<1;
		rz=(cr[0]-'0')*10+(cr[1]-'0');
		xz=(cx[0]-'0')*10+(cx[1]-'0');
		if(rz==xz){
			cout<<1;
			if(cr[2]+cx[2]=='F'+'D'){
				cout<<11;
			}
			else if(cr[2]!='D'&&cx[2]!='F'&&cr[2]!='F'&&cx[2]!='D'){
				cout<<1;
				if(cr[2]+cx[2]!='C'+'A'){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
		
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	return 0;
}


