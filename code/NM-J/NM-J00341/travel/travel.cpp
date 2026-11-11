#include<bits/stdc++.h>
using namespace std;
string Rc,Rz,Xc,Xz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>Rc>>Rz>>Xc>>Xz;
	if(Rc==Xc){
		cout<<1;
		if(Rz[0]==Xz[0]&&Rz[1]==Xz[1]){
			cout<<1;
			if(Rz[2]>='A'&&Rz[2]<='C'&&Xz[2]>='A'&&Xz[2]<='C'){
				cout<<1;
				if(Rz[2]-Xz[2]==1||Rz[2]-Xz[2]==-1) cout<<1;
				else cout<<"0";
			}
			else if(Rz[2]>='D'&&Rz[2]<='F'&&Xz[2]>='D'&&Xz[2]<='F'){
				cout<<1;
				if(Rz[2]-Xz[2]==1||Rz[2]-Xz[2]==-1) cout<<1;
				else cout<<"0";				
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
